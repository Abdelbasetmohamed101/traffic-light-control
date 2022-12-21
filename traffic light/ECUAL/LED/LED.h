/*
 * LED.h
 *
 * Created: 12/14/2022 8:33:28 PM
 *  Author:Abdelbaset Mohamed
 */ 

#ifndef  LED_H_
#define  LED_H_ 
#include "../../MCAL/DIO/DIO.h"


/************************************************************************/
/*						All Driver Function Prototypes                  */
/************************************************************************/

/* Description	: LED PIN Initialization 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void LED_init(uint8_t Led_Pin, uint8_t Led_Port);


/* Description	: LED PIN Turn On 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void LED_on(uint8_t Led_Pin, uint8_t Led_Port);


/* Description	: LED PIN Turn Off
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void LED_off(uint8_t Led_Pin, uint8_t Led_Port);


/* Description	: LED PIN Toggle 
 * INPUTS		: (2) 8-bit Inputs: PIN Number, PORT Number
 * RETURN		: non return void ( Will be set for Error Handling in the future )
 */
void LED_toggle(uint8_t Led_Pin, uint8_t Led_Port);


#endif /* LED_H_ */