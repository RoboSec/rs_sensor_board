# RoboSec Sensor Board

RoboSec board based on the ST Nucleo64 STM32F401RE board to control HC-SR04 Ultrasonic Range Sensors and WS2812 Led bars

## Pinout

### Nucleo64 [STM43F401RE]
| PIN         | Name               	| Note                                                             	|
|:-----------:|---------------------|-------------------------------------------------------------------|
| **PB0**     |Trigger sensor #0 #2	| [*GPIO STANDARD*] 																								|
| **PB1**     |Trigger sensor #1 #3	| [*GPIO STANDARD*] 																								|
| **PA2**     |Echo sensor #0      	| [*TMR9 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]		|
| **PA6**     |Echo sensor #1      	| [*TMR3 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]		|
| **PB6**     |Echo sensor #2      	| [*TMR4 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]		|
| **PA1**     |Echo sensor #3      	| [*TMR5 CH1 INPUT CAPTURE INDIRECT - CH2 INPUT CAPTURE DIRECT*]		|
| **PA0**     |WS2812 Led Driver   	| [*TMR2 CH1 PWM + DMA*]																						|
| **PA9**     |USART 1 TX					 	|																																		|
| **PA10**    |USART 1 RX					 	|																																		|
| **PA5**     |LD2 Board Green Led 	|																																		|
| **PA11**    |Light Modulation    	| [*TMR1 CH4 PWM*]																									|
| **PC0**     |Ambient Light Sensor	| [*ADC1 IN10*]																											|
| **PC1-9**	  |GPIO[0-8]					  |	9 x [*GPIO STANDARD*]																						  |
| **PC10**    |Sound Ampliefier EN  | [*GPIO STANDARD*] - *Default HIGH*                                |
| **PB8**     |I2C_SCL              | [*I2C1 Clock*]                                                    |
| **PB9**     |I2C_SDA              | [*I2C1 Data*]                                                     |
| **PA3**     |AN_IN0               | [*ADC1 IN3*]																											|
| **PA4**     |AN_IN1     	        | [*ADC1 IN4*]																											|
| **PA7**     |AN_IN2     	        | [*ADC1 IN7*]																											|

**NOTE**: Open the pads **SB13** and **SB14**, close the pads **SB62** and **SB63** in order to enable the pins **PA2** and **PA3** on the Morpho connector of the Nucleo Board (see pg 24 of the "UM1724 - User manual" document)
