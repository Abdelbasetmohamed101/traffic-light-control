/*
 * TIMERS.c
 *
 * Created: 12/14/2022 8:45:28 PM
 *  Author:Abdelbaset Mohamed
 */ 
#include "TIMERS.h"
#include "../../UTIL/BIT_MANIPULATION.h"

/************************************************************************/
/*			TIMER0 Function Definitions                     */
/************************************************************************/

/* Description	: TIMER 0 Initialization 
 * INPUTS		: (1) 8-bit Input: TIMER_MODES
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */


void TIMER0_init(uint8_t TIMER_MODES)
{
	// Check For Valid Inputs
	if(TIMER_MODES <= FAST_PWM_MODE)
	{
		switch(TIMER_MODES)
		{
			case NORMAL_MODE:			TCCR0 = 0x00; break;
			case PHASE_CORRECT_MODE:	TCCR0 = 0x40; break;
			case CTC_MODE:				TCCR0 = 0x08; break;
			case FAST_PWM_MODE:			TCCR0 = 0x48; break;
		}
	}
	else
	{
		// Error Handling
	}
}


/* Description	: TIMER 0 Start 
 * INPUTS		: (2) 8-bit Input: Timer Prescaler, Initial Timer Value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER0_start(uint8_t Timer_Prescaler, uint8_t Initial_Value1)
{
	// Set Initial Timer Value
	TCNT0 = Initial_Value1;
	
	// Check For Valid Inputs
	if(Timer_Prescaler <= PRESCALER_1024)
	{
		switch(Timer_Prescaler)
		{
			case NO_PRESCALER:
			
				SET_BIT(TCCR0, CS00);
				CLR_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS02);
				break;
			
			case PRESCALER_8:
			
				CLR_BIT(TCCR0, CS00);
				SET_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS02);
				break;
			
			case PRESCALER_64:
			
				SET_BIT(TCCR0, CS00);
				SET_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS02);
				break;
			
			case PRESCALER_256:
			
				CLR_BIT(TCCR0, CS00);
				CLR_BIT(TCCR0, CS01);
				SET_BIT(TCCR0, CS02);
				break;
				
			case PRESCALER_1024:
			
				SET_BIT(TCCR0, CS00);
				CLR_BIT(TCCR0, CS01);
				SET_BIT(TCCR0, CS02);
				break;
			}
	}
}


/* Description	: TIMER 0 Stop 
 * INPUTS		: No Inputs (void)
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER0_stop(void)
{
	TCCR0 = 0x00;
}


/* Description	: TIMER 0 Delay  
 * INPUTS		: (2) 8-bit Inputs: Timer Prescaler , Initial Timer Value --- (1) 32-bit Input: Number Of Over Flows Counter
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER0_delay(uint8_t Timer_Prescaler, uint8_t Initial_Value2, uint32_t Overflow_Num)
{
	// Reset The Over Flow Counter
	uint32_t overFlowCounter   = 0;
	
	// Start TIMER 0
	TIMER0_start(Timer_Prescaler, Initial_Value2);
	
	// Wait Until The Number Of Over Flows are Reached
	while( overFlowCounter < Overflow_Num)
	{
		/* T tick = Prescaler / FCPU
		 * FCPU = 1 000 000  
		 * One Overflow -> 256 microsecond ( NO_PRESCALER )
		 * One Overflow -> 2 048 microsecond ( PRESCALER_8 )
		 * One Overflow -> 16 384 microsecond ( PRESCALER_64 ) <-------- 
		 * One Overflow -> 65 536 microsecond ( PRESCALER_256 )
		 * One Overflow -> 262 144 microsecond ( PRESCALER_1024 )
		 */
		
		/* 1 sec = 1 000ms = 1 000 000 microseconds
		 * 1 000 000 / 16 384 = 61 FULL Overflows  ( +1 overFlow with the Initial  Value )
		 * 1 000 000 % 16 384 = 576
		 * 16 384 - 576 = 15 808
		 * 15 808 / 64 = 247 (Initial Value )
		 */
		 
		
		// wait until the overflow flag to be set
		while(GET_BIT(TIFR,TOV0) == 0);
		
		// Clear the overflow flag
		CLR_BIT(TIFR,TOV0);
		
		overFlowCounter++;
		
	}
	
	overFlowCounter = 0;
	
	TIMER0_stop();
}

/************************************************************************/
/*			TIMER2 Function Definitions                     */
/************************************************************************/


/* Description	: TIMER 2 Initialization 
 * INPUTS		: (1) 8-bit Input: TIMER_MODES
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER2_init(uint8_t TIMER_MODES)
{
	// Check For Valid Inputs
	if(TIMER_MODES <= FAST_PWM_MODE)
	{
		switch(TIMER_MODES)
		{
			case NORMAL_MODE:			TCCR2 = 0x00; break;
			case PHASE_CORRECT_MODE:	TCCR2 = 0x40; break;
			case CTC_MODE:				TCCR2 = 0x08; break;
			case FAST_PWM_MODE:			TCCR2 = 0x48; break;
		}
	}
	else
	{
		// Error Handling
	}
}


/* Description	: TIMER 2 Start 
 * INPUTS		: (2) 8-bit Input: Timer Prescaler, Initial Timer Value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER2_start(uint8_t Timer_Prescaler, uint8_t Initial_Value1)
{
	// Set Initial Timer Value
	TCNT2 = Initial_Value1;
	
	// Check For Valid Inputs
	if(Timer_Prescaler <= PRESCALER_1024)
	{
		switch(Timer_Prescaler)
		{
			case NO_PRESCALER:
			
				SET_BIT(TCCR2, CS20);
				CLR_BIT(TCCR2, CS21);
				CLR_BIT(TCCR2, CS22);
				break;
			
			case PRESCALER_8:
			
				CLR_BIT(TCCR2, CS20);
				SET_BIT(TCCR2, CS21);
				CLR_BIT(TCCR2, CS22);
				break;
			
			case PRESCALER_64:
			
				SET_BIT(TCCR2,	CS20);
				SET_BIT(TCCR2,	CS21);
				CLR_BIT(TCCR2,	CS22);
				break;
			
			case PRESCALER_256:
			
				CLR_BIT(TCCR2, CS20);
				CLR_BIT(TCCR2, CS21);
				SET_BIT(TCCR2, CS22);
				break;
			
			case PRESCALER_1024:
			
				SET_BIT(TCCR2, CS20);
				CLR_BIT(TCCR2, CS21);
				SET_BIT(TCCR2, CS22);
				break;
		}
	}
}


/* Description	: TIMER 2 Stop 
 * INPUTS		: No Inputs (void)
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER2_stop(void)
{
	TCCR2 = 0x00;
}


/* Description	: TIMER 2 Delay  
 * INPUTS		: (2) 8-bit Inputs: Timer Prescaler , Initial Timer Value --- (1) 32-bit Input: Number Of Over Flows Counter
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void TIMER2_delay(uint8_t Timer_Prescaler, uint8_t Initial_Value2, uint32_t Overflow_Num)
{
	// Reset The Over Flow Counter
	uint32_t overFlowCounter   = 0;
	
	// Start TIMER 0
	TIMER2_start(Timer_Prescaler, Initial_Value2);
	
	// Wait Until The Number Of Over Flows are Reached
	while( overFlowCounter < Overflow_Num)
	{
		
		// wait until the overflow flag to be set
		while(GET_BIT(TIFR,TOV2) == 0);
		
		// Clear the overflow flag
		CLR_BIT(TIFR,TOV2);
		overFlowCounter++;
		
	}
	
	overFlowCounter = 0;
	
	TIMER2_stop();
}