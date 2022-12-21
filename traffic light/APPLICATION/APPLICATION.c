/*
 * APPLICATION.c
 *
 * Created: 12/14/2022 8:14:55 PM
 *  Author:Abdelbaset Mohamed
 */ 

#define F_CPU 1000000UL

#include "../ECUAL/LED/LED.h"
#include "../ECUAL/BUTTON/button.h"
#include "../MCAL/TIMERS/TIMERS.h"
#include "../UTIL/BIT_MANIPULATION.h"
#include "../UTIL/INTERRUPTS.h"
#include "APPLICATION.h"


// Counters
uint8_t Counter_Of_Sec		= 0;
uint32_t overflow_Counter	= 0;
uint32_t overflow_Counter_T_2	= 0;

//Flags
uint8_t CAR_STATE		= 0;
uint8_t YELLOW_FLAG		= 0;
uint8_t FLAG_OF_BUTTONS	= 0;
uint8_t Yellow_Button_Num=0;
/************************************************************************/
/*				INITIALIZATION				*/
/************************************************************************/
void app_init()
{
	/* DIO Initialization */
	
	// Set LEDs Direction OUTPUT
	DIO_init(CAR_GREEN_PIN	,	CAR_PORT, OUTPUT);
	DIO_init(CAR_YELLOW_PIN	,	CAR_PORT, OUTPUT);
	DIO_init(CAR_RED_PIN	,	CAR_PORT, OUTPUT);
	
	DIO_init(PED_GREEN_PIN	,	PED_PORT, OUTPUT);
	DIO_init(PED_YELLOW_PIN	,	PED_PORT, OUTPUT);
	DIO_init(PED_RED_PIN	,	PED_PORT, OUTPUT);
	
	// Set Button Direction INPUT
	BUTTON_init(BUTTON_PIN, BUTTON_PORT);
	
	
	/* Interrupts Initialization */
	
	// Enable Global Interrupt
	SET_BIT(SREG, GIE);
	
	
	// INT 0 Sense Any Logical Change ( It's set that way so we can distinguish between a short and a long press )
	SET_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
	
	// Enable INT0
	SET_BIT(GICR, INT0);
	
	// Enable Overflow Interrupts for TIMER0 and TIMER2
	SET_BIT(TIMSK,TOIE0);
	SET_BIT(TIMSK,TOIE2);
	
	// Timer 0 initialization
	TIMER0_init(NORMAL_MODE);
	
	// Timer 2 initialization
	TIMER2_init(NORMAL_MODE);
	
	// Timer 0 Start
	TIMER0_start(PRESCALER_64, TIMER0_Initial_Value1);
}

/************************************************************************/
/*				 APPLICATION				*/
/************************************************************************/

void app_start()
{
	while (1)
	{
		// To Ensure GREEN -> YELLOW -> RED -> YELLOW -> GREEN... Loop
		if (CAR_STATE >YELLOW_CAR_2)
		{
			CAR_STATE = CAR_GREEN;
		}
		
		else
		{
			switch(CAR_STATE)
			{
				case CAR_GREEN:
				
					// Turn On Car GREEN led and Pedestrian RED led
					LED_on(CAR_GREEN_PIN,CAR_PORT);
					LED_off(CAR_YELLOW_PIN, CAR_PORT);
					LED_off(CAR_RED_PIN, CAR_PORT);
				
					LED_off(PED_GREEN_PIN,PED_PORT);
					LED_off(PED_YELLOW_PIN,PED_PORT);
					LED_on(PED_RED_PIN,PED_PORT);
				
					YELLOW_FLAG = 0;
					break;
				
				case CAR_YELLOW_1:
				
					// Set The Yellow Flag So it can blink 
					YELLOW_FLAG = 1;
					
					LED_off(CAR_GREEN_PIN,CAR_PORT);
					LED_off(CAR_RED_PIN, CAR_PORT);
				
					LED_off(PED_GREEN_PIN,PED_PORT);
					LED_off(PED_RED_PIN,PED_PORT);
					break;
				
				case CAR_RED:
				
					// Turn On Car RED led and Pedestrian GREEN led
					LED_off(CAR_GREEN_PIN,CAR_PORT);
					LED_off(CAR_YELLOW_PIN, CAR_PORT);
					LED_on(CAR_RED_PIN, CAR_PORT);
				
					LED_on(PED_GREEN_PIN,PED_PORT);
					LED_off(PED_YELLOW_PIN,PED_PORT);
					LED_off(PED_RED_PIN,PED_PORT);
					
					YELLOW_FLAG = 0;
					break;
				
				caseYELLOW_CAR_2:
				
					// Set The Yellow Flag So it can blink 
					YELLOW_FLAG = 1;
					
					LED_off(CAR_GREEN_PIN,CAR_PORT);
					LED_off(CAR_RED_PIN, CAR_PORT);
				
					LED_off(PED_GREEN_PIN,PED_PORT);
					LED_off(PED_RED_PIN,PED_PORT);
					break;
				
				default:
				// do nothing
				break;
			}
		}
	}
}


/**** TIMER 0 Overflow ISR ****/

ISR(TIMER0_OVF)
{
	
	
	
	
	if (Yellow_Button_Num == 1)
	{
		Yellow_Button_Num = 0;
		Counter_Of_Sec = 0;
		overflow_Counter = 0;
	}
	// Check if the overflow counter reached the number of overflows to ( 1s ) 
	
	if (overflow_Counter < TIMER0_NumOfOverFlows)
	{
		overflow_Counter++;
	}
	
	else if (overflow_Counter >= TIMER0_NumOfOverFlows)
	{
		// Increment a second
		Counter_Of_Sec++;
		
		
		if (YELLOW_FLAG == 1)
		// If The Yellow Flag is Set Toggle Both YELLOW LEDs
		{
			LED_toggle(CAR_YELLOW_PIN,CAR_PORT);
			LED_toggle(PED_YELLOW_PIN,PED_PORT);
		}
		
		if (Counter_Of_Sec == 5)
		{
			// If The Seconds Counter Counts 5 Seconds Switch To The Next Signal State
			CAR_STATE++;
			
			// Reset The Seconds Counter
			Counter_Of_Sec = 0;
		}
		
		// Reset The Overflow Counter
		overflow_Counter = 0;
	}
}


/**** TIMER 2 Overflow ISR ****/

ISR(TIMER_2_OVF)
{
	// Just Increment The Overflow Counter
	overflow_Counter_T_2++;
}


/**** EXT INT0 ISR ****/

ISR (EXT_INT_0)
{
	// Increment The Pressed Flag
	FLAG_OF_BUTTONS++;
	
	/* The Interrupt Is Set To Any Logical Change So That
	 * We Can Count The Time Between The 2 Logical Changes
	 * ( Rising Edge When Pressed and Falling When Released )
	 */
	
	switch(FLAG_OF_BUTTONS)
	{
		case PRESSED:
			
			// Start Timer2 At The Rising Edge 
			TIMER2_start(PRESCALER_64,47);
			break;
			
		case RELEASED:
		
			// Check The overflow Counter Counted More Than Half a Second Or Not
			if (overflow_Counter_T_2 > TIMER2_NumOfOverFlows)
			{
				// The Button Was Not Released Before 0.5 (aka. Long Press )
				// Do Nothing
			}
			
			// The Button Was Released Before 0.5s (aka. Short Press )
			else
			{
				if (CAR_STATE == CAR_GREEN)
				{
					// If The Car Signal Is GREEN Switch It To YELLOW
					CAR_STATE++;
					
					// Reset The Counters
					Counter_Of_Sec = 0;
					overflow_Counter = 0;
				}
				
			
				
					else if (CAR_STATE == CAR_YELLOW_1)
					{
						Yellow_Button_Num = 1;

					}
					else if (CAR_STATE ==YELLOW_CAR_2)
					{
						Yellow_Button_Num = 1;

					}
				
				
		}
		
		// Stop TIMER2
		TIMER2_stop();
		
		// Reset The Counter and The Flag
		overflow_Counter_T_2	= 0;
		FLAG_OF_BUTTONS = 0;
		break;
	}
	
}