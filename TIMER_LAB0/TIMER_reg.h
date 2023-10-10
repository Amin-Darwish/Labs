/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******                           ********/
/*******   Module:  TIMER reg      ********/
/*******   Version:     1.0        ********/
/******************************************/
/******************************************/

#ifndef TIMER_REG_H_
#define TIMER_REG_H_

/*
TCCR0	*((volatile u8*) (0x53))
TCNT0	*((volatile u8*) (0x52))
TIMSK	*((volatile u8*) (0x59))
OCR0	*((volatile u8*) (0x5C))
 */
/**************************TCCR0 Registers*************************************/
#define FOC0 	7
#define WGM00	6
#define COM01 	5
#define COM00	4
#define WGM01	3
#define CS02 	2
#define CS01 	1
#define CS00 	0
/**************************Enable TMR0 Pin*************************************/
#define TOIE0	0
#define OCIE0	1


/////////////////////////////////////////////////



#endif
