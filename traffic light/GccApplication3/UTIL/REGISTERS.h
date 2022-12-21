/*
 * REGISTERS.h
 *
 * Created: 12/14/2022 8:26:21 PM
 *  Author:Abdelbaset Mohamed
 */ 

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "TYPES.h"

/************************************************************************/
/*						All Micro controller Registers                   */
/************************************************************************/


/************************************************************************/
/*							  DIO Registers                             */
/************************************************************************/

// PORTA Registers
#define PORTA *((volatile uint8_t*)0x3B) // Dereference cause it is an address -- volatile cause it is a hardware -- 8-bit reg
#define DDRA  *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39)

// PORTB Registers
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)

// PORTC Registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)

// PORTD Registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)

/************************************************************************/
/*							  Timer Registers                           */
/************************************************************************/

#define TIFR   *((volatile uint8_t*)0x58)

// Timer 0 Registers
#define TCCR0  *((volatile uint8_t*)0x53)
#define TCNT0  *((volatile uint8_t*)0x52)

// Timer 1 Registers
#define TCCR1A  *((volatile uint8_t*)0x4F)
#define TCCR1B  *((volatile uint8_t*)0x4E)
#define TCNT1H  *((volatile uint8_t*)0x4D)
#define TCNT1L  *((volatile uint8_t*)0x4C)

// Timer 2 Registers
#define TCCR2  *((volatile uint8_t*)0x45)
#define TCNT2  *((volatile uint8_t*)0x44)

/************************************************************************/
/*						  Interrupt Registers                           */
/************************************************************************/

#define MCUCR	*((volatile uint8_t*)0x55)
#define MCUCSR	*((volatile uint8_t*)0x54)
#define GICR	*((volatile uint8_t*)0x5B)
#define GIFR	*((volatile uint8_t*)0x5A)
#define SREG	*((volatile uint8_t*)0x5F)
#define TIMSK	*((volatile uint8_t*)0x59)


#endif /* REGISTERS_H_ */

