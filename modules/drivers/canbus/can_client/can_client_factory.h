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

/**
 * @file
 * @brief Defines the CanClientFactory class.
 */

#pragma once

#include <memory>
#include <unordered_map>

#include "cyber/common/macros.h"

#include "modules/common/util/factory.h"
#include "modules/drivers/canbus/can_client/can_client.h"

/**
 * @namespace edith::drivers::canbus
 * @brief edith::drivers::canbus
 */
namespace edith {
namespace drivers {
namespace canbus {

/**
 * @class CanClientFactory
 * @brief CanClientFactory inherites edith::common::util::Factory.
 */
class CanClientFactory
    : public edith::common::util::Factory<CANCardParameter::CANCardBrand,
                                           CanClient> {
 public:
  /**
   * @brief Register the CAN clients of all brands. This function call the
   *        Function edith::common::util::Factory::Register() for all of the
   *        CAN clients.
   */
  void RegisterCanClients();

  /**
   * @brief Create a pointer to a specified brand of CAN client. The brand is
   *        set in the parameter.
   * @param parameter The parameter to create the CAN client.
   * @return A pointer to the created CAN client.
   */
  std::unique_ptr<CanClient> CreateCANClient(const CANCardParameter &parameter);

 private:
  DECLARE_SINGLETON(CanClientFactory)
};

}  // namespace canbus
}  // namespace drivers
}  // namespace edith
