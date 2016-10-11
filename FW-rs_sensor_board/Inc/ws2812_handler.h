#ifndef WS2812_HANDLER_H
#define WS2812_HANDLER_H

#include "common.h"

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)

// >>>>> Public functions
void ws2812_initLeds();

void ws2812_setColor(int ledIdx, const uint8_t *color);
void ws2812_applyColors();
void ws2812_turnOffLeds();

void ws2812_fadeEffect( uint8_t maxLevel );
// <<<<< Public functions

// >>>>> Color definitions
#define	OFF		0
#define FULL	255
#define MID		150
#define SOFT	15
static const uint8_t BLACK[] =
{ OFF, OFF, OFF };
static const uint8_t RED[] =
{ FULL, OFF, OFF };
static const uint8_t GREEN[] =
{ OFF, FULL, OFF };
static const uint8_t BLUE[] =
{ OFF, OFF, FULL };
static const uint8_t WHITE[] =
{ FULL, FULL, FULL };
static const uint8_t SOFT_WHITE[] =
{ SOFT, SOFT, SOFT };
static const uint8_t MID_WHITE[] =
{ MID, MID, MID };
static const uint8_t MID_RED[] =
{ MID, OFF, OFF };
static const uint8_t MID_GREEN[] =
{ OFF, MID, OFF };
static const uint8_t MID_BLUE[] =
{ OFF, OFF, MID };
static const uint8_t SOFT_RED[] =
{ SOFT, OFF, OFF };
static const uint8_t SOFT_GREEN[] =
{ OFF, SOFT, OFF };
static const uint8_t SOFT_BLUE[] =
{ OFF, OFF, SOFT };
// <<<<< Color definitions


#endif
