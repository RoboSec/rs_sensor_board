# RoboSec Sensor Board

RoboSec board based on the ST Nucleo64 STM32F401RE board to control Ultrasonic Sensors and WS2812 Led bars


## Pinout

### Nucleo64 [STM43F401RE]
* **PB8** - Trigger sensor #0 #2 [*TMR10 CH1 PWM SINGLE SHOT*] 
* **PB9** - Trigger sensor #1 #3 [*TMR11 CH1 PWM SINGLE SHOT*] 
* **PA0** - Echo sensor #0 [*TMR2 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA6** - Echo sensor #1 [*TMR3 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PB6** - Echo sensor #2 [*TMR4 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA1** - Echo sensor #3 [*TMR5 CH1 INPUT CAPTURE INDIRECT - CH2 INPUT CAPTURE DIRECT*]
* **PA9** - USART 1 TX
* **PA10** - USART 1 RX
* **PA2** - USART 2 TX
* **PA3** - USART 2 RX
* **PA5** - LD2 Board Green Led
