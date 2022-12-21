/*
 * DIO.c
 *
 * Created: 12/14/2022 8:44:58 PM
 *  Author:Abdelbaset Mohamed
 */ 


#include "DIO.h"
#include "../../UTIL/BIT_MANIPULATION.h"

/************************************************************************/
/*			Function Definitions                            */
/************************************************************************/

/* Description	: DIO PIN Direction Initialization 
 * INPUTS		: (3) 8-bit Inputs: PIN Number, PORT Number, Direction
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	// Check For Valid Inputs
	if ((portNumber <= PORT_D) && (pinNumber <= PIN_7))
	{
		if (direction == OUTPUT)
		{
			switch (portNumber)
			{
				case PORT_A: SET_BIT(DDRA,pinNumber);break;
				case PORT_B: SET_BIT(DDRB,pinNumber);break;
				case PORT_C: SET_BIT(DDRC,pinNumber);break;
				case PORT_D: SET_BIT(DDRD,pinNumber);break;
			}
		}
		else if (direction == INPUT)
		{
			switch (portNumber)
			{
				case PORT_A: CLR_BIT(DDRA,pinNumber);break;
				case PORT_B: CLR_BIT(DDRB,pinNumber);break;
				case PORT_C: CLR_BIT(DDRC,pinNumber);break;
				case PORT_D: CLR_BIT(DDRD,pinNumber);break;
			}
		}
		else
		{
			// Error Handling
		}
	}
}


/* Description	: Write On DIO PIN 
 * INPUTS		: (3) 8-bit Inputs: PIN Number, PORT Number, Value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	// Check For Valid Inputs
	if ((portNumber <= PORT_D) && (pinNumber <= PIN_7))
	{
		if (value == HIGH)
		{
			switch (portNumber)
			{
				case PORT_A: SET_BIT(PORTA,pinNumber);break;
				case PORT_B: SET_BIT(PORTB,pinNumber);break;
				case PORT_C: SET_BIT(PORTC,pinNumber);break;
				case PORT_D: SET_BIT(PORTD,pinNumber);break;
			}
		}
		else if (value == LOW)
		{
			switch (portNumber)
			{
				case PORT_A: CLR_BIT(PORTA,pinNumber);break;
				case PORT_B: CLR_BIT(PORTB,pinNumber);break;
				case PORT_C: CLR_BIT(PORTC,pinNumber);break;
				case PORT_D: CLR_BIT(PORTD,pinNumber);break;
			}
		}
		else
		{
			// Error Handling
		}
	}
}


/* Description	: Toggle The DIO PIN 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	// Check For Valid Inputs
	if ((portNumber <= PORT_D) && (pinNumber <= PIN_7))
	{
		switch (portNumber)
		{
			case PORT_A: TOGG_BIT(PORTA,pinNumber);break;
			case PORT_B: TOGG_BIT(PORTB,pinNumber);break;
			case PORT_C: TOGG_BIT(PORTC,pinNumber);break;
			case PORT_D: TOGG_BIT(PORTD,pinNumber);break;
		}
	}
	else
	{
		// Error Handling
	}
}


/* Description	: Read The DIO PIN value 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number --- (1) 8-bit pointer : value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	// Check For Valid Inputs
	if ((portNumber <= PORT_D) && (pinNumber <= PIN_7))
	{
		switch (portNumber)
		{
			case PORT_A: *value = GET_BIT(PINA,pinNumber);break;
			case PORT_B: *value = GET_BIT(PINB,pinNumber);break;
			case PORT_C: *value = GET_BIT(PINC,pinNumber);break;
			case PORT_D: *value = GET_BIT(PIND,pinNumber);break;
		}
	}
	else
	{
		// Error Handling
	}
}


/* Description	: DIO PORT Direction Initialization 
 * INPUTS		: (2) 8-bit Inputs: PORT Number, Direction
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_port_init(uint8_t portNumber, uint8_t direction)
{
	// Check For Valid Inputs
	if (portNumber <= PORT_D)
	{
		switch (portNumber)
		{
			case PORT_A: DDRA = direction; break;
			case PORT_B: DDRB = direction; break;
			case PORT_C: DDRC = direction; break;
			case PORT_D: DDRD = direction; break;
		}
	}
	else
	{
		// Error Handling
	}
}