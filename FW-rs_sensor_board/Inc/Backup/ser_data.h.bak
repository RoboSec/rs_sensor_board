#ifndef SER_DATA_H
#define SER_DATA_H

#include <stdint.h>
#include "ultrasnd_handler.h"

#define	MSG_ULTRASOUND	0x01

typedef struct _ultrasnd_data_out
{
  uint16_t ctrl_frame_0;   // 0xA55A
  uint8_t byte_count;   // number of bytes following
  uint8_t type;			// Message type
  uint32_t ticks;       // ticks since system start
  float not_valid_val;  // value for not valid distances
  float distances[MAX_SONAR];   // distances in meters
  uint16_t sonar_active; // Number of sonar connected;
  uint16_t ctrl_frame_1;   // 0x5AA5
} UltraSndDataOut;

#endif
