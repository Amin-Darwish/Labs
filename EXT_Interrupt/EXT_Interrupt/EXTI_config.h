/*
 * IncFile1.h
 *
 * Created: 9/9/2023 9:03:11 PM
 *  Author: amind
 */ 


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/* COMMENT WHAT ARE NOT YOU NEEDED*/
#define EXTI_LINE0_ENABLE				//-> PD2
#define EXTI_LINE1_ENABLE				//-> PD3
#define EXTI_LINE2_ENABLE               //-> PB2
 
/* change mode */
#define EXTI_LINE0_MODE   EXTI_ON_CHANGE	
#define EXTI_LINE1_MODE   EXTI_RISING_EDGE	
#define EXTI_LINE2_MODE   EXTI_FALLING_EDGE	

#endif /* EXTI_CONFIG_H_ */