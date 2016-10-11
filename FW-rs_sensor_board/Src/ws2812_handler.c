#include "ws2812_handler.h"

#include "tim.h"
#include "math.h"

#define H_VAL 75
#define L_VAL 30
#define BITS_PER_LED (3*8)
#define BIT_BUF_SIZE (((N_LEDS+1) * BITS_PER_LED) ) // Added a "virtual led" to avoid PWM to generate false bits

uint32_t ws2812BitBuf[BIT_BUF_SIZE];

void ws2812_initLeds()
{
	for (int i = 0; i < BIT_BUF_SIZE; i++)
		ws2812BitBuf[i] = 0;

	ws2812_turnOffLeds();
}

void ws2812_turnOffLeds()
{
	for (int i = 0; i < N_LEDS; i++)
		ws2812_setColor(i, BLACK);

	ws2812_applyColors();
}

void ws2812_setColor(int ledIdx, const uint8_t *color)
{
	if (ledIdx >= N_LEDS)
		return;

	uint8_t r = color[0];
	uint8_t g = color[1];
	uint8_t b = color[2];

	int i = ledIdx * BITS_PER_LED;
	uint8_t mask;
	mask = 0x80;
	while (mask)
	{
		ws2812BitBuf[i] = (mask & g) ? H_VAL : L_VAL;
		mask >>= 1;
		i++;
	}
	mask = 0x80;
	while (mask)
	{
		ws2812BitBuf[i] = (mask & r) ? H_VAL : L_VAL;
		mask >>= 1;
		i++;
	}
	mask = 0x80;
	while (mask)
	{
		ws2812BitBuf[i] = (mask & b) ? H_VAL : L_VAL;
		mask >>= 1;
		i++;
	}
}

void ws2812_applyColors()
{
	HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t*) ws2812BitBuf,
			sizeof(ws2812BitBuf) / sizeof(ws2812BitBuf[0]));
}

void ws2812_fadeEffect( uint8_t maxLevel  )
{
	uint32_t delay = (uint32_t)(ceilf(255.0/maxLevel)*2.0f);

	for (int t = 0; t < maxLevel; t++)
	{
		for (int i = 0; i < N_LEDS; i++)
		{
			uint8_t color[] =
			{ t, 0, 0 };
			ws2812_setColor(i, color);
		}

		ws2812_applyColors();
		HAL_Delay(delay); //*/
	}

	for (int t = maxLevel; t != 0; t--)
	{
		for (int i = 0; i < N_LEDS; i++)
		{
			uint8_t color[] =
			{ t, 0, 0 };
			ws2812_setColor(i, color);
		}

		ws2812_applyColors();
		HAL_Delay(delay); //*/
	}

	for (int t = 0; t < maxLevel; t++)
	{
		for (int i = 0; i < N_LEDS; i++)
		{
			uint8_t color[] =
			{ 0, t, 0 };
			ws2812_setColor(i, color);
		}

		ws2812_applyColors();
		HAL_Delay(delay); //*/
	}

	for (int t = maxLevel; t != 0; t--)
	{
		for (int i = 0; i < N_LEDS; i++)
		{
			uint8_t color[] =
			{ 0, t, 0 };
			ws2812_setColor(i, color);
		}

		ws2812_applyColors();
		HAL_Delay(delay); //*/
	}

	for (int t = 0; t < maxLevel; t++)
	{
		for (int i = 0; i < N_LEDS; i++)
		{
			uint8_t color[] =
			{ 0, 0, t };
			ws2812_setColor(i, color);
		}

		ws2812_applyColors();
		HAL_Delay(delay); //*/
	}

	for (int t = maxLevel; t != 0; t--)
	{
		for (int i = 0; i < N_LEDS; i++)
		{
			uint8_t color[] =
			{ 0, 0, t };
			ws2812_setColor(i, color);
		}

		ws2812_applyColors();
		HAL_Delay(delay); //*/
	}

	ws2812_turnOffLeds();
}

