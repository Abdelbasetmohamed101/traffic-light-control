/*
 * BUTTON.h
 *
 * Created: 12/14/2022 8:40:18 PM
 *  Author:Abdelbaset Mohamed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"

// Button State Macros
#define LOW		0
#define HIGH	1

/************************************************************************/
/*						All Driver Function Prototypes                  */
/************************************************************************/

/* Description	: Button PIN Direction Initialization 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void BUTTON_init(uint8_t Button_Pin, uint8_t Button_Port);


/* Description	: Button Read PIN Value 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number --- (1) 8-bit Pointer: Value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void BUTTON_read(uint8_t Button_Pin, uint8_t Button_Port, uint8_t *value);


#endif /* BUTTON_H_ */
