#include<avr/io.h>

int main()
{
	DDRA&=~(1<<PA3);
	DDRC|=(1<<PC5);
	PORTC&=~(1<<PC5);
	while(1)
	{
		if(PINA&(1<<PA3))
		{
			PORTC|=(1<<PC5);
		}
		else
		{
			PORTC&=~(1<<PC5);
		}
		while(PINA&(1<<PA3));

	}


}
