#ifndef WS2812_HANDLER_H
#define WS2812_HANDLER_H

#include "stm32f4xx_hal.h"
#include "tim.h"

#define TIMER_PERIOD			(htim2.Init.Period)

#define LED_NUMBER				(8)					// how many LEDs the MCU should control?
#define LED_DATA_SIZE			(LED_NUMBER * 24)
#define RESET_SLOTS_BEGIN		(50)
#define RESET_SLOTS_END			(50)
#define WS2812_LAST_SLOT		(1)
#define LED_BUFFER_SIZE			(RESET_SLOTS_BEGIN + LED_DATA_SIZE + WS2812_LAST_SLOT + RESET_SLOTS_END)
#define WS2812_0				(TIMER_PERIOD / 3)			// WS2812's zero high time is long about one third of the period
#define WS2812_1				(TIMER_PERIOD * 2 / 3)		// WS2812's one high time is long about two thirds of the period
#define WS2812_RESET			(0)


// >>>>> Public Functions
void ws2812_init(void);
void setLEDcolor(uint32_t LEDnumber, uint8_t RED, uint8_t GREEN, uint8_t BLUE);
void setWHOLEcolor(uint8_t RED, uint8_t GREEN, uint8_t BLUE);
void fillBufferBlack(void);
void fillBufferWhite(void);
// <<<<< Public Functions
#endif
