/*****************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 *  Description: Header file for adc driver
 *
 *******************************************************/


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#include "math.h"

/*******************************************************
 *               Function Prototypes
 * ****************************************************/

/*
 *
 * function responsible for initialize the adc driver
 *
 */
void ADC_init(void);


/*
 * Function responsible for read analog data from a certain channel
 *
 */

uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */
