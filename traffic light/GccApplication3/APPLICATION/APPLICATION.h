/*
 * APPLICATION.h
 *
 * Created: 12/14/2022 8:15:24 PM
 *  Author:Abdelbaset Mohamed
 */ 

#ifndef APP_H_
#define APP_H_

// PORT Macros
#define CAR_PORT				PORT_A
#define PED_PORT				PORT_B
#define BUTTON_PORT				PORT_D

// PIN Macros
#define CAR_GREEN_PIN       PIN_0
#define CAR_YELLOW_PIN      PIN_1
#define CAR_RED_PIN         PIN_2

#define PED_GREEN_PIN       PIN_0
#define PED_YELLOW_PIN      PIN_1
#define PED_RED_PIN         PIN_2

#define BUTTON_PIN          PIN_2

// Car Signal State Macros
#define CAR_GREEN				  0
#define CAR_YELLOW_1			1
#define CAR_RED					  2
#define YELLOW_CAR_2			3

// Timer Macros
#define TIMER0_Initial_Value1	247
#define TIMER0_NumOfOverFlows	62

#define TIMER2_Initial_Value1	47
#define TIMER2_NumOfOverFlows	30

// Button Macros
#define PRESSED		1
#define RELEASED	2


/* Description	: APP Initialization 
 * INPUTS		: void
 * RETURN		: void
 */
void app_init(void);


/* Description	: App Implementation
 * INPUTS		: void
 * RETURN		: void
 */
void app_start(void);

#endif /* APP_H_ */
