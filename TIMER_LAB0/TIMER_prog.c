/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******   Layer        MCAL       ********/                 
/*******   Module:      TIMER0     ********/       
/*******   Version:     1.0        ********/                     
/******************************************/                               
/******************************************/
#include "STD_types.h"
#include "BIT_math.h"
#include "Err_types.h"

#include "Atmega32_reg.h"

#include "TIMER_reg.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_interface.h"

static void (*TIMER0_pvOVFCallBackFunc)(void)= NULL;
static void (*TIMER0_pvCTCCallBackFunc)(void)= NULL;

void TIMER0_voidInit(void)
{
   /* Set CTC mode */
    CLEAR_BIT(TCCR0,WGM00);
    SET_BIT(TCCR0,WGM01);

    /*Set prescaler /256 */
    CLEAR_BIT(TCCR0,CS00);
    CLEAR_BIT(TCCR0,CS01);
    SET_BIT(TCCR0,CS02);
    /*Compare match interupt enable  */
    SET_BIT(TIMSK,OCIE0);


}

u8 TIMER0_u8SetCallBack(u8 Copy_u8IntType,void(*copy_pvCallBackFunc)(void))
{
    u8 Local_u8ErrorState= OK;

    if(copy_pvCallBackFunc != NULL)
    	if(Copy_u8IntType ==TIMER_U8_OVF_INT)
    	{
    		TIMER0_pvOVFCallBackFunc=copy_pvCallBackFunc;
    	}
    	else if(Copy_u8IntType ==TIMER_U8_CTC_INT)
    	{
    		TIMER0_pvCTCCallBackFunc=copy_pvCallBackFunc;
    	}
    	else
    	{
    		Local_u8ErrorState = NULL_POINTER;
    	}
    return Local_u8ErrorState;
}

/**Timer0 CTC ISR **/
void__vector_10(void__attribute__((signal)));
void__vector_10(void)
{
	if(TIMER0_pvCTCCallBackFunc !=NULL)
	  {
	    TIMER0_pvCTCCallBackFunc();
	   }
	else
	{
		/* Do nothing*/
	}
}
