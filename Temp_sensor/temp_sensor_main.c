/*
 * Temperature Sensor display degrees on LCD
 */
#include "adc.h"
#include "lcd.h"

int main(void)
{
	uint32 temp;
	LCD_init();
	ADC_init();
	LCD_clearScreen();
	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,10);
	LCD_displayCharacter('c');
	while(1)
	{
		LCD_goToRowColumn(0,7);
		temp = ADC_readChannel(2);
		temp = (temp*150*5)/(1023*1.5); /* claculate the temp from ADC value */
		LCD_intgerToString(temp);
	}

}
