/*****************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 *  Description: Source file for ADC driver
 *
 ******************************************************/

#include "adc.h"

/*******************************************************
 *                      Function Definitions
 ********************************************************/

void ADC_init(void)
{
	/*
	 * ADMUX Register Bits Description:
	 * REFS1:0 =00 to choose to connect external voltage by input this voltage through AREF pin
	 * ADLAR: =0 right adjusted
	 * MUX:0 = 00000 to choose channel 0 as initialization
	 */
	ADMUX =0;

	/*
	 * ADCSRA Register Bits Description:
	 * ADEN = 1 Enable ADC
	 * ADIE = 0 Disable ADC Intruppt
	 * ADPS2:0 =011 to choose ADC_Clock=F_CPU/8=125KHZ --> ADC must operate in 50KHZ to 200KHZ
	 *
	 */
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
}


uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* clear first5 bits in ADMUX */
	ADMUX = ADMUX | channel_num; /* choose the channel number */
	SET_BIT(ADCSRA,ADSC); /* START CONVERSION */
	while (BIT_IS_CLEAR(ADCSRA,ADIF)); /* wait for the conversion to complete ADIF (ADC flag) becomes true */
	SET_BIT(ADCSRA,ADIF); /*clear ADIF by write 1 to it */
    return ADC; /* return the data register */
}

