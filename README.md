# RoboSec Sensor Board

RoboSec board based on the ST Nucleo64 STM32F401RE board to control HC-SR04 Ultrasonic Range Sensors and WS2812 Led bars


## Pinout

### Nucleo64 [STM43F401RE]
* **PB0**  - Trigger sensor #0 #2 [*GPIO STANDARD*] 
* **PB1**  - Trigger sensor #1 #3 [*GPIO STANDARD*] 
* **PA0**  - Echo sensor #0       [*TMR2 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA6**  - Echo sensor #1       [*TMR3 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PB6**  - Echo sensor #2       [*TMR4 CH1 INPUT CAPTURE DIRECT - CH2 INPUT CAPTURE INDIRECT*]
* **PA1**  - Echo sensor #3       [*TMR5 CH1 INPUT CAPTURE INDIRECT - CH2 INPUT CAPTURE DIRECT*]
* **PB8**  - WS2812 Led Driver    [*TMR10 CH1 PWM + DMA*]
* **PA9**  - USART 1 TX
* **PA10** - USART 1 RX
* **PA2**  - USART 2 TX
* **PA3**  - USART 2 RX
* **PA5**  - LD2 Board Green Led
* **PA11**- Light Modulation     [*TMR1 CH4 PWM*]
