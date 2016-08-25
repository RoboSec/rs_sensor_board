#include "ser_handler.h"
#include "usart.h"
#include <string.h>

#include "light_pwm_handler.h"

#define CTRL_FRAME_0 0x5AA5 // On serial bus you will get 0xA5 0x5A sequence being Little Endian
#define CTRL_FRAME_1 0x0D0A // On serial bus you will get 0x0A (Line Feed) 0x0D (Carriage Return) sequence being Little Endian

// >>>>> Private Variables
static UltraSndDataOut usnd_ser_output;
// <<<<< Private Variables

// >>>>> Public Variables
SerialInput serInput1;
// <<<<< Public Variables

void initSerOutput(UART_HandleTypeDef* port)
{
	if (port->Instance == USART1)
	{
		// >>>>> Ultrasound message
		usnd_ser_output.ctrl_frame_0 = CTRL_FRAME_0;
		usnd_ser_output.byte_count = sizeof(UltraSndDataOut) - 2;
		usnd_ser_output.type = MSG_ULTRASOUND;
		usnd_ser_output.not_valid_val = RANGE_NOT_VALID;
		usnd_ser_output.ctrl_frame_1 = CTRL_FRAME_1;
		// <<<<< Ultrasound message
	}
}

void initSerInput(UART_HandleTypeDef* port)
{
	if (port->Instance == USART1)
	{
		serInput1.in_idx = 0;
		serInput1.in_started = 0;

		strAvailable1 = 0;

		HAL_UART_Receive_IT(&huart1, &serInput1.lastByte, 1);
	}
}

void sendMeasures()
{
	int i = 0;
	usnd_ser_output.ticks = HAL_GetTick();
	memcpy((void*) usnd_ser_output.distances, (void*) distances,
	MAX_USND_SENS * sizeof(float));

	usnd_ser_output.sonar_active = sonarCount;

	HAL_UART_Transmit(&huart1, (uint8_t*) (&usnd_ser_output),
			sizeof(UltraSndDataOut), 100);

	// >>>>> Invalidate measures
	for (i = 0; i < MAX_USND_SENS; i++)
	{
		distances[i] = RANGE_NOT_VALID;
		distValid[i] = 0;
		echo_duration[i] = 0;
	}
	// <<<<< Invalidate measures
}

//Interrupt callback routine
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1)	//current UART
	{
		if (serInput1.in_idx == 0) // clear Rx_Buffer before receiving new data
		{
			memset(serInput1.in_buffer, 0, IN_BUF_SIZE);
		}

		if (serInput1.lastByte == 0xA5 && serInput1.in_started == 0) // First Byte
		{
			serInput1.in_idx = 0;
			serInput1.in_started = 1;
		}

		serInput1.in_buffer[serInput1.in_idx] = serInput1.lastByte;

		uint8_t prevIdx = serInput1.in_idx - 1;
		if (serInput1.lastByte == 0x0D && serInput1.in_buffer[prevIdx] == 0x0A) // TODO Verify the correctness of the order of the bytes
		{
			// Transmission is complete
			memcpy(lastRecStr1, serInput1.in_buffer, IN_BUF_SIZE); // Copy all the buffer to clean the data after the terminator
			serInput1.in_idx = 0;
			serInput1.in_started = 0;

			HAL_UART_Receive_IT(huart, &serInput1.lastByte, 1); // reactivate UART receive interrupt every time

			strAvailable1 = 1;

			return;
		}

		if (serInput1.in_idx == IN_BUF_SIZE - 1)
		{
			serInput1.in_idx = 0; // Avoiding overflow
		}
		else
		{
			serInput1.in_idx++;
		}

		HAL_UART_Receive_IT(huart, &serInput1.lastByte, 1); // reactivate UART receive interrupt every time
	}
}

void parseSerData1()
{
	// Reset flag
	strAvailable1 = 0;

	// >>>>> Data size control
	uint8_t dataSize = strlen((char*) lastRecStr1);

	if (dataSize != (lastRecStr1[2] + 3))
	{
		return; // Wrong size
	}
	// <<<<< Data size control

	uint8_t type = lastRecStr1[3];

	if (type == MSG_PWM) // PWM Setting
	{
		// Data Remapping
		PwmData* pwm = (PwmData*) lastRecStr1;

		// >>>>> Redundancy control
		if (pwm->ctrl_frame_0 != CTRL_WORD_0 || pwm->ctrl_frame_1 != CTRL_WORD_1)
		{
			return; // data not correct
		}
		// <<<<< Redundancy control

		// >>>>> Data size control
		int dataSize = strlen((char*) lastRecStr1);

		if (dataSize != pwm->byte_count + 3)
		{
			return; // Wrong size
		}
		// <<<<< Data size control

		PwmStatus newStatus;
		newStatus.frequency = pwm->frequency;
		newStatus.dutyCycle = pwm->dutyCycle;

		setLightPwmStatus(&newStatus);
	}

}
