/*
 * LED.c
 *
 * Created: 12/14/2022 8:33:12 PM
 *  Author:Abdelbaset Mohamed
 */ 
#include "LED.h"

/************************************************************************/
/*			Function Definitions                            */
/************************************************************************/

/* Description	: LED PIN Initialization 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void LED_init(uint8_t Led_Pin, uint8_t Led_Port)
{
	DIO_init(Led_Pin, Led_Port, OUTPUT);
}


/* Description	: LED PIN Turn On 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void LED_on(uint8_t Led_Pin, uint8_t Led_Port)
{
	DIO_write(Led_Pin, Led_Port, HIGH);
}


/* Description	: LED PIN Turn Off
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void LED_off(uint8_t Led_Pin, uint8_t Led_Port)
{
	DIO_write(Led_Pin, Led_Port, LOW);
}


/* Description	: LED PIN Toggle 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void LED_toggle(uint8_t Led_Pin, uint8_t Led_Port)
{
	DIO_toggle(Led_Pin, Led_Port);
}