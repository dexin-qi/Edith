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

#include "cyber/cyber.h"
#include "cyber/proto/unit_test.pb.h"
#include "cyber/py_wrapper/py_cyber.h"

edith::cyber::PyReader *pr = nullptr;

int cbfun(const char *channel_name) {
  AINFO << "recv->[ " << channel_name << " ]";
  if (pr) {
    AINFO << "read->[ " << pr->read() << " ]";
  }
  return 1;
}

int main(int argc, char *argv[]) {
  edith::cyber::Init("cyber_python");
  edith::cyber::proto::Chatter chat;
  edith::cyber::PyNode node("listener");
  pr = node.create_reader("channel/chatter", chat.GetTypeName());
  pr->register_func(cbfun);

  edith::cyber::WaitForShutdown();
  delete pr;

  return 0;
}
