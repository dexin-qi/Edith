/**
 * @file peak_can_client_test.cc
 * @author DustinKsi (dustinksi@126.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <sstream>
#include <string>

#include "modules/drivers/canbus/can_client/peak/peak_can_client.h"
#include "modules/drivers/canbus/common/byte.h"
#include "gtest/gtest.h"

namespace edith {
namespace drivers {
namespace canbus {
namespace can {

using edith::common::ErrorCode;

TEST(PeakCANClient, constructor) {
  CANCardParameter param;
  param.set_brand(CANCardParameter::PEAK_CAN);
  param.set_channel_id(CANCardParameter::CHANNEL_ID_ZERO);
  PeakCanClient peak_can;
}

TEST(PeakCANClient, receiver) {
  CANCardParameter param;
  param.set_brand(CANCardParameter::PEAK_CAN);
  param.set_channel_id(CANCardParameter::CHANNEL_ID_ZERO);
  PeakCanClient peak_can;
  EXPECT_TRUE(peak_can.Init(param));
  EXPECT_EQ(peak_can.Start(), ErrorCode::OK);

  // std::vector<CANFrame> send_frames;
  // CANFrame open_pdo;
  // open_pdo.id = 0x00;
  // open_pdo.type = CANMsgType::STANDARD;
  // open_pdo.len = 2;
  // open_pdo.data[0] = 0x01;
  // // open_pdo.data[1] = 0x01;
  // // send_frames.push_back(open_pdo);
  // open_pdo.data[1] = 0x02;
  // send_frames.push_back(open_pdo);
  // int32_t send_num = send_frames.size();
  // peak_can.Send(send_frames, &send_num);

  // std::vector<CANFrame> recv_frames;
  // int32_t recv_num = 5;
  // for (int i = 0; i < 10; i++) {
  //   EXPECT_EQ(peak_can.Receive(&recv_frames, &recv_num), ErrorCode::OK);
  //   for (auto cf : recv_frames) {
  //     std::stringstream bytes_ss;
  //     for (uint8_t i = 0; i < cf.len; i++) {
  //       bytes_ss << Byte::byte_to_hex(cf.data[i]) << (i + 1 == cf.len ? "" : " ");
  //     }
  //     timeval ts = cf.timestamp;
  //     D_INFO << "[" << ts.tv_sec << "." << ts.tv_usec << "] ID: 0x" << std::hex << std::setw(4)
  //            << cf.id << ", len: " << std::to_string(cf.len) << ", data: [" << bytes_ss.str()
  //            << "]";
  //   }
  // }

  // peak_can.Stop();
}

}  // namespace can
}  // namespace canbus
}  // namespace drivers
}  // namespace edith

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}