#include "light_pwm_handler.h"

#include "tim.h"

// >>>>> Public Variables
PwmStatus pwmStatus;
// <<<<< Public Variables

// >>>>> Private Functions
void setLightPwmFrequency(float freq);
void setLightPwmDutyCycle(float duty);
// <<<<< Private Functions

void initLightPwm()
{
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

void lightPwmBootTest()
{
	for (int i = 0; i < 100; i++)
	{
		float duty = (float) i * 0.01f;
		setLightPwmDutyCycle(duty);

		HAL_Delay(10);
	}

	for (int i = 100; i != 0; i--)
	{
		float duty = (float) i * 0.01f;
		setLightPwmDutyCycle(duty);

		HAL_Delay(10);
	}

	setLightPwmDutyCycle(0.0f);
}

void setLightPwmStatus(PwmStatus* status)
{
	setLightPwmFrequency(status->frequency);
	setLightPwmDutyCycle(status->dutyCycle);
}

void setLightPwmFrequency(float freq)
{
	pwmStatus.frequency = freq;

// Note: the prescaler is set to 84, so we have a
//       system frequency of 1000000 Hz (SysClock is 84 Mhz)

	float period_usec = 1e6 / freq - 1;

	htim1.Instance->ARR = (uint32_t) period_usec;

// Reset correct Duty Cycle
//setLightPwmDutyCycle( pwmStatus.dutyCycle );
}

// Note: pulse_length = ((TIM_Period + 1) * Duty_Cycle) - 1

void setLightPwmDutyCycle(float duty)
{
	pwmStatus.dutyCycle = duty;

	uint32_t pulse = (uint32_t) (((float) (htim1.Instance->ARR + 1)) * duty)
			- 1;

	TIM1->CCR4 = pulse;
}
