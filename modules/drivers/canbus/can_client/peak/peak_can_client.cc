/**
 * @file peak_can_client.cc
 * @author DustinKsi (dustinksi@126.com)
 * @brief
 * @version 0.1
 * @date 2020-02-23
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "modules/drivers/canbus/can_client/peak/peak_can_client.h"

#include <stdio.h>
#include <string.h>
#include <vector>

#include <iostream>

namespace edith {
namespace drivers {
namespace canbus {
namespace can {

using edith::common::ErrorCode;

PeakCanClient::~PeakCanClient() { Stop(); }

bool PeakCanClient::Init(const CANCardParameter &options) {
  if (options.channel_id() != CANCardParameter::CHANNEL_ID_ZERO) {
    AERROR << "Init CAN failed: channel id in options is invalid."
              "options: "
           << options.DebugString();
    return false;
  } else {
    _card_port = options.channel_id();
    return true;
  }
}

ErrorCode PeakCanClient::Start() {
  _is_init = false;

  if (_is_init) {
    return ErrorCode::OK;
  }

  if (_card_port > MAX_CAN_PORT || _card_port < 0) {
    AERROR << "can port number [" << _card_port << "] is out of the range [0," << MAX_CAN_PORT
           << "]";
    return ErrorCode::CAN_CLIENT_ERROR_BASE;
  }

  AINFO << "Try to load peak CAN board ...";

  // open device
  int count = 0;
  bool _is_connected = false;
  while (count < 3) {
    AINFO << "Try to open canbus! times: [" << count << "]";
    if (CAN_Initialize(PCAN_USBBUS1, PCAN_BAUD_500K, 0, 0, 0) == PCAN_ERROR_OK) {
      AINFO << "Open device succ on PCAN_USBBUS1";
      _is_connected = true;
      break;
    } else {
      AERROR << "Open device error!";
    }
    count++;
    usleep(1000000);  // sleep 0.1s
  }

  CAN_GetValue(PCAN_USBBUS1, PCAN_RECEIVE_EVENT, &fd, sizeof(int));

  /* Watch stdin (fd 0) to see when it has input. */
  FD_ZERO(&Fds);
  FD_SET(fd, &Fds);

  if (!_is_connected) {
    return ErrorCode::CAN_CLIENT_ERROR_BASE;
  }

  _is_init = true;
  return ErrorCode::OK;
}

void PeakCanClient::Stop() {
  if (_is_init) {
    _is_init = false;
    CAN_Uninitialize(PCAN_USBBUS1);
  }
}

ErrorCode PeakCanClient::Send(const std::vector<CanFrame> &frames, int32_t *const frame_num) {
  /*typedef struct tagTPCANMsg
    {
        DWORD             ID;      // 11/29-bit message identifier
        TPCANMessageType  MSGTYPE; // Type of the message
        BYTE              LEN;     // Data Length Code of the message (0..8)
        BYTE              DATA[8]; // Data of the message (DATA[0]..DATA[7])
    } TPCANMsg;*/

  size_t buffer_size = static_cast<size_t>(*frame_num);
  CHECK_NOTNULL(frame_num);
  CHECK_EQ(frames.size(), buffer_size);

  if (!_is_init) {
    AERROR << "Peak CAN client is not initialized!";
    return ErrorCode::CAN_CLIENT_ERROR_SEND_FAILED;
  }

  for (int i = 0; i < *frame_num; ++i) {
    _send_frames[i].ID = frames[i].id;

    if (frames[i].len == 8) {
      _send_frames[i].MSGTYPE = PCAN_MESSAGE_STANDARD;
    } else if (frames[i].len == 0) {
      _send_frames[i].MSGTYPE = PCAN_MESSAGE_RTR;
    } else {
      AERROR << "CAN not judge canbus msg type: STANDARD/RTR";
    }

    if (frames[i].len != 0) {
      _send_frames[i].LEN = frames[i].len;
      memcpy(_send_frames[i].DATA, frames[i].data, frames[i].len);
    }
  }

  // Synchronous transmission of CAN messages
  for (size_t cnt = 0; cnt < buffer_size; cnt++) {
    if (CAN_Write(PCAN_USBBUS1, _send_frames) != PCAN_ERROR_OK) {
      return ErrorCode::CAN_CLIENT_ERROR_SEND_FAILED;
    }
  }

  return ErrorCode::OK;
}

ErrorCode PeakCanClient::Receive(std::vector<CanFrame> *const frames, int32_t *const frame_num) {
  if (!_is_init) {
    AERROR << "Peak CAN client is not init! Please init first!";
    return ErrorCode::CAN_CLIENT_ERROR_RECV_FAILED;
  }
  if (*frame_num > MAX_CAN_RECV_FRAME_LEN || *frame_num < 0) {
    AERROR << "Receive can frame num not in range[0, " << MAX_CAN_RECV_FRAME_LEN
           << "], frame_num:" << *frame_num;
    return ErrorCode::CAN_CLIENT_ERROR_FRAME_NUM;
  }

  const int timeout_ceil = 10;
  timeval timeout_val;
  timeout_val.tv_sec = 0;
  timeout_val.tv_usec = 100;

  int cnt = 0, timeout_cnt = 0;
  while (true) {
    timeout_cnt = 0;
    while (select(fd + 1, &Fds, NULL, NULL, &timeout_val) <= 0) {
      timeout_cnt++;
      if (timeout_cnt < timeout_ceil) {
        AERROR << "Receive can frame timeout, max than 1ms.";
        return ErrorCode::CAN_CLIENT_ERROR_RECV_FAILED;
      }
    }
    if (CAN_Read(PCAN_USBBUS1, _recv_frames + cnt, _recv_ts + cnt) == PCAN_ERROR_OK) {
      timeout_cnt = 0;
      cnt++;
    } else {
      return ErrorCode::CAN_CLIENT_ERROR_RECV_FAILED;
    }
    if (cnt >= *frame_num) {
      break;
    }
  }

  for (int32_t i = 0; i < *frame_num && i < MAX_CAN_RECV_FRAME_LEN; ++i) {
    CanFrame cf;
    cf.id = _recv_frames[i].ID;
    cf.len = _recv_frames[i].LEN;

    cf.timestamp.tv_sec = _recv_ts[i].millis_overflow * UINT32_MAX + _recv_ts[i].millis / 1000;
    cf.timestamp.tv_usec = (_recv_ts[i].millis % 1000) * 1000 + _recv_ts[i].micros;

    std::memcpy(cf.data, _recv_frames[i].DATA, _recv_frames[i].LEN);
    frames->push_back(cf);
  }

  return ErrorCode::OK;
}

std::string PeakCanClient::GetErrorString(int32_t ntstatus) { return ""; }

void PeakCanClient::SetInited(bool init) { _is_init = init; }

}  // namespace can
}  // namespace canbus
}  // namespace drivers
}  // namespace edith
