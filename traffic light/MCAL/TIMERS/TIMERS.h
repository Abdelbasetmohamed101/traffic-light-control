/*
 * TIMERS.h
 *
 * Created: 12/14/2022 8:45:44 PM
 *  Author:Abdelbaset Mohamed
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "../../UTIL/REGISTERS.h"

/************************************************************************/
/*							All Driver Macros                           */
/************************************************************************/

// TIMER Mode Macros
#define NORMAL_MODE			0
#define PHASE_CORRECT_MODE  1
#define CTC_MODE			2
#define FAST_PWM_MODE		3

// Prescaler Macros
#define NO_PRESCALER	0
#define PRESCALER_8		1
#define PRESCALER_64	2
#define PRESCALER_256	3
#define PRESCALER_1024	4

//TIMSK
#define TOIE0	0
#define OCIE0	1
#define TOIE1	2
#define OCIE1B	3
#define OCIE1A	4
#define TICIE1	5
#define TOIE2	6
#define OCIE2	7

// TCCR0
#define CS00 0
#define CS01 1
#define CS02 2

// TCCR2
#define CS20 0
#define CS21 1
#define CS22 2

// TIFR
#define TOV0 0
#define TOV2 6


/************************************************************************/
/*						All Timers Function Prototypes                  */
/************************************************************************/

/* Description	: TIMER 0 Initialization 
 * INPUTS		: (1) 8-bit Input: TIMER_MODES
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER0_init(uint8_t TIMER_MODES);					


/* Description	: TIMER 0 Start 
 * INPUTS		: (2) 8-bit Input: Timer Prescaler, Initial Timer Value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER0_start(uint8_t Timer_Prescaler, uint8_t Initial_Value1);	


/* Description	: TIMER 0 Stop 
 * INPUTS		: No Inputs (void)
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER0_stop(void);											


/* Description	: TIMER 0 Delay  
 * INPUTS		: (2) 8-bit Inputs: Timer Prescaler , Initial Timer Value --- (1) 32-bit Input: Number Of Over Flows Counter
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER0_delay(uint8_t Timer_Prescaler, uint8_t Initial_Value2, uint32_t Overflow_Num);		



/* Description	: TIMER 2 Initialization 
 * INPUTS		: (1) 8-bit Input: TIMER_MODES
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER2_init(uint8_t TIMER_MODES);

/* Description	: TIMER 2 Start 
 * INPUTS		: (2) 8-bit Input: Timer Prescaler, Initial Timer Value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER2_start(uint8_t Timer_Prescaler, uint8_t Initial_Value1);


/* Description	: TIMER 2 Stop 
 * INPUTS		: No Inputs (void)
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER2_stop(void);


/* Description	: TIMER 2 Delay  
 * INPUTS		: (2) 8-bit Inputs: Timer Prescaler , Initial Timer Value --- (1) 32-bit Input: Number Of Over Flows Counter
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER2_delay(uint8_t Timer_Prescaler, uint8_t Initial_Value2, uint32_t Overflow_Num);

#endif /* TIMERS_H_ */