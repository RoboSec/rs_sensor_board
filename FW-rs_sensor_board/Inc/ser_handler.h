#ifndef SER_HANDLER_H_
#define SER_HANDLER_H_

#include "ser_data.h"
#include "tim.h"

// >>>>> Public Variables
extern SerialInput serInput1;
// <<<<< Public Variables


void initSerOutput( UART_HandleTypeDef* port ); // Initialize serial output
void initSerInput( UART_HandleTypeDef* port ); // Initialize serial input

void parseSerData1(); // Parse a complete string received on UART1

void sendMeasures(); // Send Range Sensor Measures on UART1

#endif
