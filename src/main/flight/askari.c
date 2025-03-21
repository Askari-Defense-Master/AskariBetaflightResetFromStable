#include "askari.h"

#include <math.h>
#include <stdint.h>
#include <string.h>

#include "common/maths.h"
#include "common/streambuf.h"
#include "common/utils.h"
#include "fc/runtime_config.h"

#include "msp/msp_protocol.h"

#include "flight/imu.h"
#include "flight/position.h"

#include "sensors/acceleration.h"
#include "sensors/barometer.h"
#include "sensors/compass.h"
#include "sensors/gyro.h"
#include "sensors/gyro_init.h"

#include "rx/rx.h"
#include "rx/msp.h"

#include "io/beeper.h"
#include "fc/rc_modes.h"

#define PACKET_TIMEOUT_US 100000  // 1/10Hz =100ms in microseconds - 10Hz

enum AXIS { // roll, pitch, throttle, yaw, aux1, aux2
  ROLL = 0,
  PITCH,
  THROTTLE,
  YAW,
  AUX1,
  AUX2
};

int16_t askariSetpoints[3] = {0,0,0}; //This holds roll [Decidegrees],pitch [Decidegrees], and maybe yaw [Degrees/s] commands

pidAskari_t pidAskari = {
    .derivateGains = {1.0, 1.0},
    .integralGains = {0.5, 0.5}
};

bool useAskari = false;

// static void askariMspFrameReceive(uint16_t *frame, int channelCount)
// {
//   for (int i = 0; i<channelCount;i++)
//   {
//     if (i == ROLL || i == PITCH)
//     {
//        //To ensure that the system does to RX failsage
//       // if (i == YAW)
//       //   askariSetpoints[i-1]  = (int16_t)frame[i]; // Reinterpret as int16_t
//       // else
//       //   askariSetpoints[i]  = (int16_t)frame[i]; // Reinterpret as int16_t
//       if (i == ROLL || i == PITCH)
//       {
//           askariSetpoints[i] = (int16_t)frame[i];
//       }
//       frame[i] = 1500;
        
//         // askariSetpoints[i] = frame[i];
//     }
//   }
// }

mspResult_e mspProcessAskariCommand(mspDescriptor_t srcDesc, int16_t cmdMSP,
                                    sbuf_t *src, sbuf_t *dst) {
  UNUSED(srcDesc);

  const unsigned int dataSize = sbufBytesRemaining(src);
  //---
  switch (cmdMSP) {
  case MSP_ASKARI: {
    //Handle the RX receive
    uint8_t channelCount = dataSize / sizeof(uint16_t);
    if (channelCount > SUPPORTED_STATE_CHANNEL_COUNT) {
      return MSP_RESULT_ERROR;
    } else {
      uint16_t frame[SUPPORTED_STATE_CHANNEL_COUNT];
      for (int i = 0; i < channelCount; i++) {
        frame[i] = sbufReadU16(src);
      }

      rxMspFrameReceive(frame, channelCount); //to set aux1,aux2,throttle and yaw
    }

    // SENDING BACK ATTITUDE DATA
    sbufWriteU16(dst, attitude.values.roll);
    sbufWriteU16(dst, attitude.values.pitch);
    sbufWriteU16(dst, attitude.values.yaw);
    break;
  }
  default:
    return MSP_RESULT_CMD_UNKNOWN;
  }
  return MSP_RESULT_ACK;
}