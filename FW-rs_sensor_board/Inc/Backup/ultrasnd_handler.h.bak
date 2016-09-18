#ifndef ULTRASND_HANDLER_H
#define ULTRASND_HANDLER_H
#include "tim.h"

#define MAX_DURATION_10_USEC 2500 ///< Max duration of the echo: 25 msec -> about 4 m

#define MAX_USND_SENS   4 ///< Max number of sensors that can be connected to the board
#define RANGE_NOT_VALID   	99999.99f ///< Value used for not valid distances

#define COUPLE_0_2   0 ///< Id to trigger Sonar #0 and Sonar #2
#define COUPLE_1_3   1 ///< Id to trigger Sonar #1 and Sonar #3

#define USND_SENS_0 0   ///< Sensor #0 index
#define USND_SENS_1 1   ///< Sensor #1 index
#define USND_SENS_2 2   ///< Sensor #2 index
#define USND_SENS_3 3   ///< Sensor #3 index

// >>>>> Global Variables
extern int sonarCount; ///< The number of sonars connected to the board
extern volatile float distances[MAX_USND_SENS];  ///< Last distances
extern volatile uint32_t echo_duration[MAX_USND_SENS];   ///< Times measured by Input Capture
extern volatile uint8_t distValid[MAX_USND_SENS]; ///< Distance valid indicators
extern volatile uint32_t trigger_tick[MAX_USND_SENS/2];
extern volatile uint32_t elapsed_tick[MAX_USND_SENS];
// <<<<< Global Variables

// >>>>> Public functions
/*! brief Initializes structures
 *
 * @param sonar_count the number of sonars connected to the board
 */
void initUsndSensors( int sonar_count );

/*! brief Emits trigger for a couple of sonars
 *
 * @param couple a couple of sonars [@ref COUPLE_0_2 or @ref COUPLE_1_3]
 */
void triggerUsndSensors( int couple );

/*! brief Updates @ref times vector on Input Capture interrupt
 */
//void onNewMeasureReceived( TIM_HandleTypeDef *htim );

/*! brief Converts echo duration from @ref times vector to distance values in
 *        @ref distances vector
 */
void convertMeasures();

void waitEcho( int couple );
// <<<<< Public functions

#endif
