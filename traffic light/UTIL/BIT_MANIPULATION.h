/*
 * BIT_MANIPULATION.h
 *
 * Created: 12/14/2022 8:23:18 PM
 *  Author:Abdelbaset Mohamed
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SET_BIT(Reg,n) Reg|=(1<<n)
#define CLR_BIT(Reg,n) Reg&=~(1<<n)
#define GET_BIT(Reg,n) ((Reg>>n)&1)
#define TOGG_BIT(Reg,n) Reg^=(1<<n)


#endif /* BIT_MANIPULATION_H_ */