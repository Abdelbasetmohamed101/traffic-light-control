/*
 * DIO.h
 *
 * Created: 12/14/2022 8:44:34 PM
 *  Author:Abdelbaset Mohamed
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "../../UTIL/REGISTERS.h"
#include "../../UTIL/TYPES.h"
#include "../INTERRUPTS/INTERRUPTS.h"

/************************************************************************/
/*							All Driver Macros                           */
/************************************************************************/

// PORT Macros
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

// PIN Macros
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
 
// PIN Direction Macros
#define INPUT	0
#define OUTPUT	1

// PORT Direction Macros
#define PORT_INPUT	0x00
#define PORT_OUTPUT 0xFF

// Value Macros
#define LOW		0
#define HIGH	1

/************************************************************************/
/*						All Driver Function Prototypes                  */
/************************************************************************/

/* Description	: DIO PIN Direction Initialization 
 * INPUTS		: (3) 8-bit Inputs: PIN Number, PORT Number, Direction
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);


/* Description	: Write On DIO PIN 
 * INPUTS		: (3) 8-bit Inputs: PIN Number, PORT Number, Value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);	
		
					
/* Description	: Toggle The DIO PIN 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);				


/* Description	: Read The DIO PIN value 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number --- (1) 8-bit pointer : value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);	


/* Description	: DIO PORT Direction Initialization 
 * INPUTS		: (2) 8-bit Inputs: PORT Number, Direction
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_port_init(uint8_t portNumber, uint8_t direction);	


/* Description	: Write On DIO PORT 
 * INPUTS		: (2) 8-bit Inputs: PORT Number, value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void DIO_port_write(uint8_t portNumber, uint8_t value);	

#endif /* DIO_H_ */
