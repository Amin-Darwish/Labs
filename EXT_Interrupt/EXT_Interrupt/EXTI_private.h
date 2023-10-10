/*
 * EXTI_private.h
 *
 * Created: 9/9/2023 9:08:13 PM
 *  Author: amind
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR    *((volatile u8 *)0x55)
#define MCUCSR   *((volatile u8 *)0x54)
#define GICR     *((volatile u8 *)0x5B)
#define GIFR     *((volatile u8 *)0x5A)

#define NULL 0

#endif

