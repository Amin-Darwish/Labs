/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******   Layer        MCAL       ********/                 
/*******   Module:      TIMER0     ********/       
/*******   Version:     1.0        ********/                     
/******************************************/
/******************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TIMER_U8_OVF_INT    0
#define TIMER_U8_CTC_INT    1

void TIMER0_voidInit(void);

u8 TIMER0_u8SetCallBack(u8 Copy_u8IntType,void(*copy_pvCallBackFunc)(void));



#endif
