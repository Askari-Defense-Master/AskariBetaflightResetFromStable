#include "askari.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#include "common/maths.h"
#include "common/streambuf.h"
#include "common/utils.h"

#include "msp/msp_protocol.h"

#include "flight/imu.h"

#include "sensors/acceleration.h"
#include "sensors/compass.h"
#include "sensors/gyro.h"
#include "sensors/gyro_init.h"

#include "rx/msp.h"
#include "rx/rx.h"

enum AXIS { // roll, pitch, throttle, yaw, aux1, aux2
  ROLL = 0,
  PITCH,
  THROTTLE,
  YAW,
  AUX1,
  AUX2
};

mspResult_e mspProcessAskariCommand(mspDescriptor_t srcDesc, int16_t cmdMSP,
                                    sbuf_t *src, sbuf_t *dst) {
  UNUSED(srcDesc);

  const unsigned int dataSize = sbufBytesRemaining(src);
  switch (cmdMSP) {
  case MSP_ASKARI: {
    // Handle the RX receive
    uint8_t channelCount = dataSize / sizeof(uint16_t);
    if (channelCount > SUPPORTED_STATE_CHANNEL_COUNT) {
      return MSP_RESULT_ERROR;
    } else {
      uint16_t frame[SUPPORTED_STATE_CHANNEL_COUNT];
      for (int i = 0; i < channelCount; i++) {
        frame[i] = sbufReadU16(src);
      }
      rxMspFrameReceive(frame,
                        channelCount); // to set aux1,aux2,throttle and yaw
    }

    // SENDING BACK ATTITUDE DATA
    sbufWriteU16(dst, attitude.values.roll);
    sbufWriteU16(dst, attitude.values.pitch);
    sbufWriteU16(dst, attitude.values.yaw);

    // SENDING BACK GYRO DATA
    for (int i = 0; i < 3; i++) {
      sbufWriteU16(dst, gyroRateDps(i));
    }
    break;
  }
  default:
    return MSP_RESULT_CMD_UNKNOWN;
  }
  return MSP_RESULT_ACK;
}