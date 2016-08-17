#include "tim_handler.h"
#include "leds_handler.h"
#include "ultrasnd_handler.h"

// Callback for Timer timeout
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM11)
	{
		// Heart beat led frequency: 2hz
		static uint8_t count = 5;

		count--;

		if (count == 0)
		{
			count = 5;
			// Nucleo Led Blink
			toggleLedNucleo();
		}
	}
}

// Callback for sonar echo
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	int idx;
	uint32_t ic_val = 0;

	// >>>>> Which sonar has received the echo?
	if (htim->Instance == TIM2)
	{
		idx = SONAR_0;
		elapsed_tick[idx] = HAL_GetTick() - trigger_tick[COUPLE_0_2];

		// Update Input Capture times
		ic_val = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
	}
	else if (htim->Instance == TIM3)
	{
		idx = SONAR_1;
		elapsed_tick[idx] = HAL_GetTick() - trigger_tick[COUPLE_0_2];

		// Update Input Capture times
		ic_val = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
	}
	else if (htim->Instance == TIM4)
	{
		idx = SONAR_2;
		elapsed_tick[idx] = HAL_GetTick() - trigger_tick[COUPLE_1_3];

		// Update Input Capture times
		ic_val = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
	}
	else if (htim->Instance == TIM5)
	{
		idx = SONAR_3;
		elapsed_tick[idx] = HAL_GetTick() - trigger_tick[COUPLE_1_3];

		// Update Input Capture times
		ic_val = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
	}
	else
		return; // Should never be here!!!
	// <<<<< Which sonar has received the echo?

	// >>>>> Durations update
	if (ic_val > MAX_DURATION_10_USEC)
		distValid[idx] = 0;
	else
		distValid[idx] = 1;

	echo_duration[idx] = ic_val;
	// <<<<< Durations update
}
