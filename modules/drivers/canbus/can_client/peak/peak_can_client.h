/******************************************************************************
 * Copyright 2020 The Edith Authors. All Rights Reserved.
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

#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include "gflags/gflags.h"
#include "modules/common/proto/error_code.pb.h"
#include "modules/drivers/canbus/can_client/can_client.h"
#include "modules/drivers/canbus/common/canbus_consts.h"
#include "modules/drivers/canbus/proto/can_card_parameter.pb.h"

#include "modules/drivers/canbus/can_client/peak/PCANBasic.h"

namespace edith {
namespace drivers {
namespace canbus {
namespace can {

/**
 * @class PeakCanClient
 * @brief The class which defines a Peak Can client which inherits CanClient.
 */

class PeakCanClient : public CanClient {
 public:
  /**
   * @brief Initialize the Peak Can client by specified CAN card parameters.
   * @param parameter CAN card parameters to initialize the CAN client.
   */
  // explicit PeakCanClient(const CANCardParameter &parameter);

  /**
   * @brief Destructor
   */
  virtual ~PeakCanClient();

  /**
   * @brief Start the Peak Can client.
   * @return The status of the start action which is defined by
   *         edith::common::ErrorCode .
   */
  bool Init(const CANCardParameter &options) override;

  /**
   * @brief Start the Peak CAN client.
   * @return The status of the start action which is defined by
   *         edith::common::ErrorCode .
   */
  edith::common::ErrorCode  Start() override;

  /**
   * @brief Stop the Peak CAN client.
   */
  virtual void Stop();

  /**
   * @brief Send messages
   * @param frames The messages to send.
   * @param frame_num The amount of messages to send.
   * @return The status of the sending action which is defined by
   *         edith::common::ErrorCode .
   */
  virtual edith::common::ErrorCode Send(const std::vector<CanFrame> &frames,
                                        int32_t *const frame_num);

  /**
   * @brief Receive messages
   * @param frames The messages to receive.
   * @param frame_num The amount of messages to receive.
   * @return The status of the receiving action which is defined by
   *         edith::common::ErrorCode .
   */
  virtual edith::common::ErrorCode Receive(std::vector<CanFrame> *const frames,
                                           int32_t *const frame_num);
  /**
   * @brief Get the error string.
   * @param status The status to get the error string.
   */
  virtual std::string GetErrorString(const int32_t status);
  /**
   * @brief Set inited status.
   * @param if status is inited.
   */
  void SetInited(bool init);

 private:
  bool _is_init = false;
  CANCardParameter::CANChannelId _card_port;

  fd_set Fds;
  int fd;
  
  TPCANMsg _send_frames[MAX_CAN_SEND_FRAME_LEN];
  TPCANMsg _recv_frames[MAX_CAN_RECV_FRAME_LEN];
  TPCANTimestamp _recv_ts[MAX_CAN_RECV_FRAME_LEN];
};

}  // namespace can
}  // namespace canbus
}  // namespace drivers
}  // namespace edith
