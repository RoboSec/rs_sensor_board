#include "ultrasnd_handler.h"
#include "common.h"

#define HALF_SOUND_SPEED_10USEC (171.605e-5) // m/usec -> the time is measured in base 10 microsecond

#define SONAR_TIMEOUT   200

// >>>>> Global Variables
int sonarCount;
volatile float distances[MAX_USND_SENS]; // Last distances
volatile uint32_t echo_duration[MAX_USND_SENS];  // Times measured by Input Capture
volatile uint8_t distValid[MAX_USND_SENS]; // Distance valid indicators
volatile uint32_t trigger_tick[MAX_USND_SENS / 2];
volatile uint32_t elapsed_tick[MAX_USND_SENS];
// <<<<< Global Variables

void initUsndSensors(int sonar_count)
{
	int i = 0;
	for (i = 0; i < MAX_USND_SENS; i++)
	{
		distances[i] = RANGE_NOT_VALID;
		distValid[i] = 0;
	}

	sonarCount = sonar_count;

	// >>>>> Turn off trigger pins
	HAL_GPIO_WritePin( TRG_SENS__0__2_GPIO_Port, TRG_SENS__0__2_Pin,
					GPIO_PIN_RESET);
	HAL_GPIO_WritePin( TRG_SENS__1__3_GPIO_Port, TRG_SENS__1__3_Pin,
					GPIO_PIN_RESET);
	// <<<<< Turn off trigger pins

	// >>>>> Enable interrupt to receive Echoes
	if (sonarCount >= 1)
		HAL_TIM_IC_Start_IT(&htim9, TIM_CHANNEL_1);
	if (sonarCount >= 2)
		HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_2);
	if (sonarCount >= 3)
		HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_2);
	if (sonarCount == 4)
		HAL_TIM_IC_Start_IT(&htim5, TIM_CHANNEL_1);
	// <<<<< Enable interrupt to receive Echoes
}

void triggerUsndSensors(int couple)
{
	// Note: in this version the trigger is "manual", no
	//       timer is used to generate the pulse

	if (couple == COUPLE_0_2) // Trigger for Sonars #0 and #2
	{
		//HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
		HAL_GPIO_WritePin( TRG_SENS__0__2_GPIO_Port, TRG_SENS__0__2_Pin,
				GPIO_PIN_SET);

		delayUS(10);
		HAL_GPIO_WritePin( TRG_SENS__0__2_GPIO_Port, TRG_SENS__0__2_Pin,
				GPIO_PIN_RESET);

		trigger_tick[COUPLE_0_2] = HAL_GetTick();
		elapsed_tick[USND_SENS_0] = 0;
		elapsed_tick[USND_SENS_2] = 0;
	}
	else if (couple == COUPLE_1_3) // Trigger for Sonars #1 and #3
	{
		//HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
		HAL_GPIO_WritePin( TRG_SENS__1__3_GPIO_Port, TRG_SENS__1__3_Pin,
				GPIO_PIN_SET);
		delayUS(10);
		HAL_GPIO_WritePin( TRG_SENS__1__3_GPIO_Port, TRG_SENS__1__3_Pin,
				GPIO_PIN_RESET);

		trigger_tick[COUPLE_1_3] = HAL_GetTick();
		elapsed_tick[USND_SENS_1] = 0;
		elapsed_tick[USND_SENS_3] = 0;
	}
}

void convertMeasures()
{
	int i = 0;
	for (i = 0; i < MAX_USND_SENS; i++)
	{
		if (distValid[i] == 1)
		{
			// v = s/t -> s = v*t = 0.5*340*t -> the space is the double of the distance, it's a roundtrip
			float range_m = (float) echo_duration[i] * HALF_SOUND_SPEED_10USEC;

			distances[i] = range_m;
		}
		else
			distances[i] = RANGE_NOT_VALID;
	}
}

void waitEcho(int couple)
{
	uint32_t startTick = HAL_GetTick();

	if (couple == COUPLE_0_2)
	{
		uint32_t elapsed = 0;
		while (!(distValid[USND_SENS_0] == 1 && distValid[USND_SENS_2] == 1))
		{
			elapsed = HAL_GetTick() - startTick;
			if (elapsed > SONAR_TIMEOUT)
				return;
		}
	}
	else if (couple == COUPLE_1_3)
	{
		uint32_t elapsed = 0;
		while (!(distValid[USND_SENS_1] == 1 && distValid[USND_SENS_3] == 1))
		{
			elapsed = HAL_GetTick() - startTick;
			if (elapsed > SONAR_TIMEOUT)
				return;
		}
	}
}

/*void onNewMeasureReceived( TIM_HandleTypeDef *htim )
 {
 // Update Input Capture times
 uint32_t ic_val = HAL_TIM_ReadCapturedValue( htim, TIM_CHANNEL_2 );

 int idx;

 // >>>>> Which sonar has received the echo?
 if( htim->Instance == TIM1 )
 idx=SONAR_0;
 else if( htim->Instance == TIM2 )
 idx=SONAR_1;
 else if( htim->Instance == TIM3 )
 idx=SONAR_2;
 else if( htim->Instance == TIM15 )
 idx=SONAR_3;
 // <<<<< Which sonar has received the echo?

 // >>>>> Durations update
 times[idx]=ic_val;
 distValid[idx] = 1;
 // <<<<< Durations update
 }*/

