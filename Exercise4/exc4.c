#include<avr/io.h>
#include<util/delay.h>
int main()
{
	DDRB&=~(1<<PB0);
	PORTB|=(1<<PB0);
	DDRC|=(1<<PC0);
	PORTC|=(1<<PC0);
	while(1)
	{
		if(PINB&(1<<PB0))
		{

		}
		else
		{
			PORTC^=(1<<PC0);
			_delay_ms(500);
		}

	}

}
