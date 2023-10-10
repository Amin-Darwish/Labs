/*
 * EXT_Interrupt.c
 *
 * Created: 9/9/2023 8:16:20 PM
 * Author : amind
 */ 

#include "BIT_math.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "PORT_interface.h"
#include "DIO_interface.h"

void Led_on(void);
void Led_off(void);
int main(void)
{ 
	PORT_voidInit();
	GIE_voidEnable();
	EXTI_voidEnable(EXTI_INT0,EXTI_FALLING_EDGE);
	EXTI_voidEnable(EXTI_INT1,EXTI_FALLING_EDGE);
    EXTI_u8SetCallBack(EXTI_INT0,&Led_on);
	EXTI_u8SetCallBack(EXTI_INT1,&Led_off);
	
    while (1) 
    {
		
	}
}

void Led_on(void)
{
	DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_HIGH);
}

void Led_off(void)
{
	DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_LOW);
}
