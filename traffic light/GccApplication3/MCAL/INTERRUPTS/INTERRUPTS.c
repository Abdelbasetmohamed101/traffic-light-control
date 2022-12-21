/*
 * INTERRUPTS.c
 *
 * Created: 12/18/2022 11:51:24 PM
 *  Author: ELMADINA
 */ 
#include "interrupts.h"
void INT_init(void)
{
	/*
		Description: this function initialize external interrupt 0 and its sense to rising edge
		inputs: none
		outputs: none
		return: none
	*/
	sei();
	MCUCR |= (1 << 0) | (1 << 1);
	// 3.Enable External interrupt 0(INT0)
	GICR |= (1 << 6);
	
}