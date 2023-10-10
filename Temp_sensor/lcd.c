/*****************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 *  Description: Source file for LCD driver
 *
 ******************************************************/

#include "lcd.h"

/*******************************************************
 *                      Function Definitions
 ********************************************************/

void LCD_init(void)
{
	LCD_DATA_PORT_DIR = 0xFF; /// configure the data port as output port
	LCD_CTRL_PORT_DIR |=(1<<E) |(1<<RS)|(1<<RW); ///configure the control pins (E,RS,RW)

	LCD_sendCommand(TWO_LINE_LCD_EIGHT_BIT_MODE); /* use 2-line lcd and 8 bit Data Mode */

	LCD_sendCommand(CURSOR_OFF); /* cursor off */

	LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */

}

void LCD_sendCommand(uint8 command)
{
	CLEAR_BIT(LCD_CTRL_PORT,RS); /* Instruction Mode RS=0 */
	CLEAR_BIT(LCD_CTRL_PORT,RW); /* Write data to LCD RW =0 */
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT,E);  /* Enable LCD E=1 */
	_delay_ms(1);
	LCD_DATA_PORT = command; /* Out the command instruction to LCD */
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT,E); /* Disable LCD E=0 */
	_delay_ms(1);

}

void LCD_displayCharacter(uint8 data)
{
	    SET_BIT(LCD_CTRL_PORT,RS); /* Data Mode RS=0 */
		CLEAR_BIT(LCD_CTRL_PORT,RW); /* Write data to LCD RW =0 */
		_delay_ms(1);
		SET_BIT(LCD_CTRL_PORT,E);  /* Enable LCD E=1 */
		_delay_ms(1);
		LCD_DATA_PORT = data; /* Out the Data Char  to LCD */
		_delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT,E); /* Disable LCD E=0 */
		_delay_ms(1);

}

void LCD_displayString(const char *str)
{
	uint8 i = 0;
	while(str[i] != '\0')
	{
		LCD_displayCharacter(str[i]);
		i++;
	}
}

void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 address;

	switch(row)
	{
	 case 0:
		    address = col;
		    break;
	 case 1:
			address = col+0x40;
			break;
	 case 2:
			address = col+0x10;
			break;
	 case 3:
			address = col+0x50;
			break;
	}

	LCD_sendCommand(address | SET_CURSOR_LOCATION);

}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *str)
{
	LCD_goToRowColumn(row,col); //go to require LCD position
	LCD_displayString(str); // Display the string

}

void LCD_intgerToString(int data)
{
	char buff[16]; // string to hold ASCII result
	itoa(data,buff,10); // 10 base for decimal
	LCD_displayString(buff);
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); // clear display
}
