#include<avr/io.h>
#include<util/delay.h>
int main()
{
	DDRB|=(1<<PB0)|(1<<PB1);     //INPUT (switches)
	PORTB&=~(1<<PB0)&~(1<<PB1);
	DDRC|=(1<<PC0)|(1<<PC1);      //output leds
	PORTC&=~(1<<PC0)&~(1<<PC1);
	while(1)
	{
		PORTC&=~(1<<PC0)&~(1<<PC1);
		if(PINB&(1<<PB0))
		{   if(PINB&(1<<PB1))
		    {
			PORTC|=(1<<PC0)|(1<<PC1);
		    }

			PORTC|=(1<<PC0);
			_delay_ms(500);
		}
		else if(PINB&(1<<PB1))
		{   if(PINB&(1<<PB0))
	       {
		    PORTC|=(1<<PC0)|(1<<PC1);
	       }
			PORTC|=(1<<PC1);
			_delay_ms(500);
		}



		}


}


