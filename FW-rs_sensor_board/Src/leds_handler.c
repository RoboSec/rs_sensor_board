#include "leds_handler.h"
#include "common.h"

void setLedNucleo( uint8_t state )
{
  if( state==LED_ON ) 
    HAL_GPIO_WritePin( STATUS_LED_GPIO_Port, STATUS_LED_Pin, GPIO_PIN_RESET );
  else
    HAL_GPIO_WritePin( STATUS_LED_GPIO_Port, STATUS_LED_Pin, GPIO_PIN_SET );
}

void toggleLedNucleo( void )
{
	STATUS_LED_GPIO_Port->ODR ^= STATUS_LED_Pin;
}
