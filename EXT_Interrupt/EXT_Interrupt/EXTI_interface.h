/*
 * interface.h
 *
 * Created: 9/9/2023 8:21:36 PM
 *  Author: amind
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "BIT_math.h"
#include "STD_types.h"
                
 #define EXTI_INT0  0         //-> PD2
 #define EXTI_INT1  1		 //-> PD3
 #define EXTI_INT2  2		 //-> PB2

#define EXTI_FALLING_EDGE	0
#define EXTI_RISING_EDGE	1
#define EXTI_LOW_LEVEL		2
#define EXTI_ON_CHANGE		3

/* EXTERNAL INTERRUPT 0 BITS*/
#define GICR_INT0_BIT	6
#define MCUCR_ISC00_BIT	0
#define MCUCR_ISC01_BIT	1
#define GIFR_INTF0_BIT	6

/* EXTERNAL INTERRUPT 1 BITS*/
#define GICR_INT1_BIT	7
#define MCUCR_ISC10_BIT	2
#define MCUCR_ISC11_BIT	3
#define GIFR_INTF1_BIT	7

/* EXTERNAL INTERRUPT 2 BITS*/
#define GICR_INT2_BIT	5
#define MCUCSR_ISC2_BIT	2
#define GIFR_INTF2_BIT	5

void EXTI_voidEnable(u8 Copy_u8IntNum, u8 Copy_u8SenseMode );
void EXTI_voidDisable( u8 Copy_u8IntNum );
void EXTI_voidClearFlag( u8 Copy_u8IntNum );

u8 EXTI_u8SetCallBack(u8 Copy_u8IntNum, void(*Copy_pvCallBackFunc)(void));

#endif 