/*
 * INTERRUPTS.h
 *
 * Created: 12/14/2022 8:24:03 PM
 *  Author:Abdelbaset Mohamed
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../../UTIL/REGISTERS.h"
/************************************************************************/
/*						    Interrupt Bits Macros			    		*/
/************************************************************************/

// MCUCR
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

// MCUCSR
#define ISC2 6

// GICR
#define INT2 5
#define INT0 6
#define INT1 7

// GIFR
#define INTF2 5
#define INTF0 6
#define INTF1 7

// SREG
#define GIE 7

/************************************************************************/
/*							Interrupts	Vectors				     		*/
/************************************************************************/

#define EXT_INT_0		__vector_1        

#define TIMER_2_OVF		__vector_5           

#define TIMER0_OVF		__vector_11          

#define  sei() __asm__ __volatile__ ("sei" ::: "memory");
   
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

void INT_init(void);
#endif /* INTERRUPTS_H_ */