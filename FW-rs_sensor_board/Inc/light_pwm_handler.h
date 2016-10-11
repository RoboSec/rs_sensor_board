#ifndef LIGHT_PWM_HANDLER_H_
#define LIGHT_PWM_HANDLER_H_

typedef struct _pwm_status
{
	float frequency;
	float dutyCycle;
} PwmStatus;

// >>>>> Public Variables
extern PwmStatus pwmStatus;
// <<<<< Public Variables

// >>>>> Public Functions
void initLightPwm();
void lightPwmBootTest();
void setLightPwmStatus( PwmStatus* status );
// <<<<< Public Functions

#endif //LIGHT_PWM_HANDLER_H_
