#include "STD_Types.h"
#include "BIT_math.h"
#include "DIO_interface.h"
#include "PORT_interface.h"

#include "TIMER_interface.h"


void LED_Tog(void);

void main (void)
{
   PORT_voidInit();
   TIMER_void_Init();
   TIMER0_u8SetCallBack(TIMER_U8_CTC_INT, &LED_Tog);
}

void LED_Tog(void)
{
	static u8 Local_u8State=0;
	DIO_voidSetPinVal(DIO_U8_PORTD, DIO_U8_PIN3, Local_u8State);
    TOGGLE_BIT(Local_u8State,0);
}

