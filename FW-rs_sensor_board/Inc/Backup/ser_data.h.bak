#ifndef SER_DATA_H
#define SER_DATA_H

#include <stdint.h>
#include "ultrasnd_handler.h"

#define	MSG_ULTRASOUND	0x01
#define MSG_PWM			0X02

#define IN_BUF_SIZE		256
#define IN_STRING_SIZE	256

#define CTRL_WORD_0	0xA55A
#define CTRL_WORD_1 0x0D0A

// >>>>> Public variables
extern uint8_t strAvailable1; // Indicates that a new string is ready to be parsed on UART1
extern uint8_t lastRecStr1[IN_STRING_SIZE];
// <<<<< Public variables

typedef struct _ultrasnd_data_out
{
	uint16_t ctrl_frame_0;		// 0xA55A
	uint8_t byte_count;   		// number of bytes following
	uint8_t type;				// Message type
	uint32_t ticks;       		// ticks since system start
	float not_valid_val;  		// value for not valid distances
	float distances[MAX_SONAR];	// distances in meters
	uint16_t sonar_active; 		// Number of sonar connected;
	uint16_t ctrl_frame_1;  	// 0x0D0A
} UltraSndDataOut; // 20 bytes

typedef struct _pwm_data
{
	uint16_t ctrl_frame_0;	// 0xA55A
	uint8_t byte_count;   	// number of bytes following
	uint8_t type;			// Message type
	float frequency;  		// Frequency of the PWM
	float dutyCycle;   		// Duty Cycle
	uint16_t ctrl_frame_1;  // 0x0D0A
} PwmData; // 14 bytes

typedef struct _serial_input
{
	uint8_t lastByte;
	uint8_t in_buffer[IN_BUF_SIZE];
	uint16_t in_idx;
	uint8_t in_started;
} SerialInput;

#endif
