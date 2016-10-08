#include "common.h"

#include "ultrasnd_handler.h"
#include "ws2812_handler.h"

void delayUS(uint32_t us)
{
	volatile uint32_t counter = 12 * us;
	while (counter--)
		;
}

void sonarLedColors()
{
	for (int i = 0; i < MAX_USND_SENS; i++)
	{
		uint8_t color[3];

		if (distances[i] != RANGE_NOT_VALID)
		{
			float val = distances[i] / 4.0f * 255.0f;

			uint8_t green = (uint8_t) val;
			uint8_t red = 255 - red;

			color[0] = red;
			color[1] = green;
			color[2] = 0;
		}
		else
		{
			color[0] = 0;
			color[1] = 15;
			color[2] = 0;
		}

		if (i == 0) // Front Sonar
		{
			ws2812_setColor(3, color);
			ws2812_setColor(4, color);
		}
		else if (i == 1) // Left Sonar
		{
			ws2812_setColor(6, color);
			ws2812_setColor(7, color);
		}
		else if (i == 2) // Rear Sonar
		{
			ws2812_setColor(2, color);
			ws2812_setColor(5, color);
		}
		else if (i == 3) // Right Sonar
		{
			ws2812_setColor(0, color);
			ws2812_setColor(1, color);
		}

	}
	ws2812_applyColors();
}
