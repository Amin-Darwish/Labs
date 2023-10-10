/*
 * UART_Test.c
 *
 * Created: 9/7/2023 7:51:46 PM
 * Author : amind
 */ 
#include "uart.h"

int main(void)
{   
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);	
    UART_init();
	u8 d;
	u8 h;
	
	//h = UART_receiveString();
    while (1) 
    {
	 d = UART_receiveByte(); 
		 
		switch (d)
		{
			case '1':
			    SET_BIT(PORTD,5);
				
			break;
			case '2':
			  CLEAR_BIT(PORTD,5);
			
				
			break;
		}
		
		
		
    }
}

