#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "FreeRTOS.h"
#include "task.h"

void LED1(void *pv);
void LED2(void *pv);
void LED3(void *pv);

void main (void)
{  
	 PORT_voidInit();
	
	xTaskCreate(&LED1,NULL,150,NULL,1,NULL);
	xTaskCreate(&LED2,NULL,150,NULL,2,NULL);
	xTaskCreate(&LED3,NULL,150,NULL,3,NULL);
	vTaskStartScheduler();
	while(1)
	{
	}
}

void LED1(void *pv)
{
	static u8 Local_u8LedState=0;
	
	while(1)
	{
		TOGGLE_BIT(Local_u8LedState,0);
		DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN2,Local_u8LedState);
		vTaskDelay(1000);
	}
}

void LED2(void *pv)
{
	static u8 Local_u8LedState=0;
	
	while(1)
	{
		TOGGLE_BIT(Local_u8LedState,0);
		DIO_voidSetPinVal(DIO_U8_PORTC,DIO_U8_PIN7,Local_u8LedState);
		vTaskDelay(2000);
	}
}
void LED3(void *pv)
{
	static u8 Local_u8LedState=0;
	
	while(1)
	{
		TOGGLE_BIT(Local_u8LedState,0);
		DIO_voidSetPinVal(DIO_U8_PORTD,DIO_U8_PIN3,Local_u8LedState);
		vTaskDelay(3000);
	}
}
