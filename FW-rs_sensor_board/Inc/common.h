#ifndef COMMON_H_
#define COMMON_H_

#include "mxconstants.h"
#include "stm32f4xx_hal.h"

#define N_LEDS (8)

void delayUS( uint32_t uSec );
void sonarLedColors();

#endif // COMMON_H_
