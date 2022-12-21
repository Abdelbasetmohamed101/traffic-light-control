/*
 * BUTTON.c
 *
 * Created: 12/14/2022 8:39:39 PM
 *  Author:Abdelbaset Mohamed
 */ 
#include "BUTTON.h"

/************************************************************************/
/*			Function Definitions                            */
/************************************************************************/

/* Description	: Button PIN Direction Initialization 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void BUTTON_init(uint8_t Button_Pin, uint8_t Button_Port)
{
	DIO_init(Button_Pin,Button_Port, INPUT);
}


/* Description	: Button Read PIN Value 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number --- (1) 8-bit Pointer: Value
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void BUTTON_read(uint8_t Button_Pin, uint8_t Button_Port, uint8_t *value)
{
	DIO_read(Button_Pin, Button_Port, value);
}