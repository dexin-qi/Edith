/******************************************************************************
 * Copyright 2020 The Edith Author. All Rights Reserved.
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

#ifndef TOOLS_CVT_MONITOR_CYBER_TOPOLOGY_MESSAGE_H_
#define TOOLS_CVT_MONITOR_CYBER_TOPOLOGY_MESSAGE_H_

#include <map>
#include <string>

#include "cyber/tools/cyber_monitor/renderable_message.h"

namespace edith {
namespace cyber {
namespace proto {
class ChangeMsg;
class RoleAttributes;
}  // namespace proto
}  // namespace cyber
}  // namespace edith

class GeneralChannelMessage;
// class GeneralMessage;

class CyberTopologyMessage : public RenderableMessage {
 public:
  explicit CyberTopologyMessage(const std::string& channel);
  ~CyberTopologyMessage();

  void Render(const Screen* s, int key) override;
  RenderableMessage* Child(int index) const override;

  void TopologyChanged(const edith::cyber::proto::ChangeMsg& change_msg);
  void AddReaderWriter(const edith::cyber::proto::RoleAttributes& role,
                       bool isWriter);

 private:
  CyberTopologyMessage(const CyberTopologyMessage&) = delete;
  CyberTopologyMessage& operator=(const CyberTopologyMessage&) = delete;

  void ChangeState(const Screen* s, int key);
  bool isFromHere(const std::string& nodeName);

  std::map<std::string, GeneralChannelMessage*>::const_iterator findChild(
      int index) const;

  enum class SecondColumnType { MessageType, MessageFrameRatio };
  SecondColumnType second_column_;

  int pid_;
  int col1_width_;
  const std::string& specified_channel_;
  std::map<std::string, GeneralChannelMessage*> all_channels_map_;
};

#endif  // TOOLS_CVT_MONITOR_CYBER_TOPOLOGY_MESSAGE_H_
