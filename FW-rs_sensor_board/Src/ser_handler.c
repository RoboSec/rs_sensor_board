#include "ser_handler.h"
#include "usart.h"
#include <string.h>


#define CTRL_FRAME_0 0x5AA5 // On serial bus you will get 0xA5 0x5A sequence being Little Endian
#define CTRL_FRAME_1 0x0D0A // On serial bus you will get 0x0A (Line Feed) 0x0D (Carriage Return) sequence being Little Endian

// >>>>> Private Variables
static UltraSndDataOut usnd_ser_output;
// <<<<< Private Variables

void initSerOutput()
{
	// >>>>> Ultrasound message
	usnd_ser_output.ctrl_frame_0 = CTRL_FRAME_0;
	usnd_ser_output.byte_count = sizeof(UltraSndDataOut)-2;
	usnd_ser_output.type = MSG_ULTRASOUND;
	usnd_ser_output.not_valid_val = NOT_VALID;
	usnd_ser_output.ctrl_frame_1 = CTRL_FRAME_1;
	// <<<<< Ultrasound message
}

void sendMeasures()
{
	int i=0;
	usnd_ser_output.ticks = HAL_GetTick();
	memcpy( (void*)usnd_ser_output.distances, (void*)distances, MAX_SONAR*sizeof(float) );

	usnd_ser_output.sonar_active = sonarCount;

	HAL_UART_Transmit( &huart1, (uint8_t*)(&usnd_ser_output), sizeof(UltraSndDataOut), 100 );


	// >>>>> Invalidate measures
	for( i=0; i<MAX_SONAR; i++ )
	{
		distances[i]=NOT_VALID;
		distValid[i] = 0;
		echo_duration[i] = 0;
	}
	// <<<<< Invalidate measures
}
