#include<avr/io.h>
#include<util/delay.h>
int main()
{
	DDRD|=(1<<PC6);
	PORTD|=(1<<PC6);
	while(1)
	{
		PORTD^=(1<<PC6);
		_delay_ms(500);
	}


}
