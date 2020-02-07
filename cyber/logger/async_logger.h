/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef CYBER_LOGGER_ASYNC_LOGGER_H_
#define CYBER_LOGGER_ASYNC_LOGGER_H_

#include <atomic>
#include <condition_variable>
#include <cstdint>
#include <ctime>
#include <deque>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "cyber/common/macros.h"
#include "glog/logging.h"

namespace apollo {
namespace cyber {
namespace logger {

/**
 * @class AsyncLogger
 * @brief 对 glog 中 Logger 的封装，以实现日志消息的异步写入。此类将启动单独的线程负责将消息转发到
 * Logger，并执行双缓冲。当自缓冲区写文件的线程启动时，会触发对记录线程的唤醒。记录线程会将
 * 写文件线程运行中累积的全部日志写入一个新的缓冲区，在写文件的线程运行结束后，交换两个缓冲区。
 *
 * 这种双缓冲设计极大地提高了性能，特别是对于需要刷新底层文件的日志消息（默认为 WARNING
 * 及以上等级）。刷新的操作可能需要几毫秒，在某些情况下会阻塞主线程数百毫秒、甚至更长。
 * 使用双缓冲方法，当日志文件IO线程被阻塞时，主线程仍然可以进行后续操作。
 *
 * 该封装的语义相比 glog 要稍弱一些。默认情况下，glog将立即（同步地）刷新 WARNING
 * 及以上等级相应的底层文件，而该封装将该刷新延迟转移到单独的线程。这意味着 ‘LOG_WARN’
 * 之后的崩溃信息有可能会丢失。我们确实注意到一个 glog 的 FATAL
 * 级错误在退出之前刷新了所有缓冲日志消息。
 *
 * @warning
 * 记录器限制了缓冲区的内存总量，以防止内存使用失控。因此：如果底层日志刷新时的阻塞时间过长，
 * 最终生成日志消息的线程也将被阻塞。
 */
class AsyncLogger : public google::base::Logger {
 public:
  explicit AsyncLogger(google::base::Logger* wrapped);

  ~AsyncLogger();

  /**
   * @brief start the async logger
   */
  void Start();

  /**
   * @brief Stop the thread. Flush() and Write() must not be called after this.
   * NOTE: this is currently only used in tests: in real life, we enable async
   * logging once when the program starts and then never disable it.
   * REQUIRES: Start() must have been called.
   */
  void Stop();

  /**
   * @brief Write a message to the log. Start() must have been called.
   *
   * @param force_flush is set by the GLog library based on the configured
   * '--logbuflevel' flag.
   * Any messages logged at the configured level or higher result in
   * 'force_flush' being set to true, indicating that the message should be
   * immediately written to the log rather than buffered in memory.
   * @param timestamp is the time of write a message
   * @param message is the info to be written
   * @param message_len is the length of message
   */
  void Write(bool force_flush, time_t timestamp, const char* message, int message_len) override;

  /**
   * @brief Flush any buffered messages.
   */
  void Flush() override;

  /**
   * @brief Get the current LOG file size.
   * The return value is an approximate value since some
   * logged data may not have been flushed to disk yet.
   *
   * @return the log file size
   */
  uint32_t LogSize() override;

  /**
   * @brief get the log thead
   *
   * @return the pointer of log thread
   */
  std::thread* LogThread() { return &log_thread_; }

 private:
  // A buffered message.
  //
  // TODO(todd): using std::string for buffered messages is convenient but not
  // as efficient as it could be. It's better to make the buffers just be
  // Arenas and allocate both the message data and Msg struct from them, forming
  // a linked list.
  struct Msg {
    time_t ts;
    std::string message;
    int32_t level;
    Msg() : ts(0), message(), level(google::INFO) {}
    Msg(time_t ts, std::string&& message, int32_t level)
        : ts(ts), message(std::move(message)), level(level) {}
    Msg(const Msg& rsh) {
      ts = rsh.ts;
      message = rsh.message;
      level = rsh.level;
    }
    Msg(Msg&& rsh) {
      ts = rsh.ts;
      message = rsh.message;
      level = rsh.level;
    }
    Msg& operator=(Msg&& rsh) {
      ts = rsh.ts;
      message = std::move(rsh.message);
      level = rsh.level;
      return *this;
    }
    Msg& operator=(const Msg& rsh) {
      ts = rsh.ts;
      message = rsh.message;
      level = rsh.level;
      return *this;
    }
  };

  void RunThread();
  void FlushBuffer(const std::unique_ptr<std::deque<Msg>>& msg);

  google::base::Logger* const wrapped_;
  std::thread log_thread_;

  // Count of how many times the writer thread has flushed the buffers.
  // 64 bits should be enough to never worry about overflow.
  std::atomic<uint64_t> flush_count_ = {0};

  // Count of how many times the writer thread has dropped the log messages.
  // 64 bits should be enough to never worry about overflow.
  uint64_t drop_count_ = 0;

  // The buffer to which application threads append new log messages.
  std::unique_ptr<std::deque<Msg>> active_buf_;

  // The buffer currently being flushed by the logger thread, cleared
  // after a successful flush.
  std::unique_ptr<std::deque<Msg>> flushing_buf_;

  // Trigger for the logger thread to stop.
  enum State { INITTED, RUNNING, STOPPED };
  std::atomic<State> state_ = {INITTED};
  std::atomic_flag flag_ = ATOMIC_FLAG_INIT;

  DISALLOW_COPY_AND_ASSIGN(AsyncLogger)
};

}  // namespace logger
}  // namespace cyber
}  // namespace apollo

#endif  // CYBER_LOGGER_ASYNC_LOGGER_H_
