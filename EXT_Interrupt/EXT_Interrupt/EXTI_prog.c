/*
 * CFile1.c
 *
 * Created: 9/9/2023 8:32:42 PM
 *  Author: amind
 */ 

#include "BIT_math.h"
#include "STD_types.h"
#include "Err_types.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"


/* Array of global pointers to functions to hold ISR addresses*/
static void (*EXTI_pvCallBackFunc[3])(void)={ NULL};
	
void EXTI_voidEnable(u8 Copy_u8IntNum, u8 Copy_u8SenseMode )
 {
   
   
	switch (Copy_u8IntNum) 
	{

	case EXTI_INT0:
		SET_BIT(GICR, GICR_INT0_BIT);
		   switch (Copy_u8SenseMode)
		     {
		        case EXTI_LOW_LEVEL:
		        	CLEAR_BIT(MCUCR, MCUCR_ISC00_BIT);
		        	CLEAR_BIT(MCUCR, MCUCR_ISC01_BIT);
		        	break;
		        case EXTI_ON_CHANGE:
		        	SET_BIT(MCUCR, MCUCR_ISC00_BIT);
		        	CLEAR_BIT(MCUCR, MCUCR_ISC01_BIT);
		        	break;
		        case EXTI_FALLING_EDGE:
		        	CLEAR_BIT(MCUCR, MCUCR_ISC00_BIT);
		        	SET_BIT(MCUCR, MCUCR_ISC01_BIT);
		        	break;
		        case EXTI_RISING_EDGE:
		        	SET_BIT(MCUCR, MCUCR_ISC00_BIT);
		        	SET_BIT(MCUCR, MCUCR_ISC01_BIT);
		        	break;
		       }
		break;

	case EXTI_INT1:
		SET_BIT(GICR, GICR_INT1_BIT);
		switch (Copy_u8SenseMode) {
		case EXTI_LOW_LEVEL:
			CLEAR_BIT(MCUCR, MCUCR_ISC10_BIT);
			CLEAR_BIT(MCUCR, MCUCR_ISC11_BIT);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR, MCUCR_ISC10_BIT);
			CLEAR_BIT(MCUCR, MCUCR_ISC11_BIT);
			break;
		case EXTI_FALLING_EDGE:
			CLEAR_BIT(MCUCR, MCUCR_ISC10_BIT);
			SET_BIT(MCUCR, MCUCR_ISC11_BIT);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR, MCUCR_ISC10_BIT);
			SET_BIT(MCUCR, MCUCR_ISC11_BIT);
			break;
		}
		break;

	case EXTI_INT2:
		SET_BIT(GICR, GICR_INT2_BIT);
		switch (Copy_u8SenseMode) {
		case EXTI_FALLING_EDGE:
			CLEAR_BIT(MCUCSR, MCUCSR_ISC2_BIT);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR, MCUCSR_ISC2_BIT);
			break;
		}
		break;
	}
}

void EXTI_voidDisable(u8 Copy_u8IntNum) {
	switch (Copy_u8IntNum) {
		case EXTI_INT0:
		CLEAR_BIT(GICR, GICR_INT0_BIT);
		break;
		case EXTI_INT1:
		CLEAR_BIT(GICR, GICR_INT1_BIT);
		break;
		case EXTI_INT2:
		CLEAR_BIT(GICR, GICR_INT2_BIT);
		break;
	}
}


void EXTI_voidClearFlag(u8 Copy_u8IntNum) {
	switch (Copy_u8IntNum) {
		case EXTI_INT0:
		SET_BIT(GIFR, GIFR_INTF0_BIT);
		break;
		case EXTI_INT1:
		SET_BIT(GIFR, GIFR_INTF1_BIT);
		break;
		case EXTI_INT2:
		SET_BIT(GICR, GICR_INT2_BIT);
		break;
	}
}

u8 EXTI_u8SetCallBack(u8 Copy_u8IntNum, void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Copy_pvCallBackFunc != NULL)
	{ 
			if (Copy_u8IntNum < 3)
			{
				EXTI_pvCallBackFunc[Copy_u8IntNum]=Copy_pvCallBackFunc;
			}
			else
			{
				Local_u8ErrorState= NOK;
			}	
	}
	else
	{
		Local_u8ErrorState = NULL_POINTR;
	}
}

/*INT0 ISR */
void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if (EXTI_pvCallBackFunc[EXTI_INT0] != NULL)
	{
		EXTI_pvCallBackFunc[EXTI_INT0](); 
	}
}

/*INT1 ISR */
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
		if (EXTI_pvCallBackFunc[EXTI_INT1] != NULL)
		{
			EXTI_pvCallBackFunc[EXTI_INT1]();
		}

}

/*INT2 ISR */
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
		if (EXTI_pvCallBackFunc[EXTI_INT2] != NULL)
		{
			EXTI_pvCallBackFunc[EXTI_INT2]();
		}

}