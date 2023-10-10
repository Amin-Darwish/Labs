/*****************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 *  Description: Header file for UART driver
 *
 *******************************************************/

#ifndef UART_H_
#define UART_H_


#include "STD_types.h"
#include "BIT_math.h"


/******************************************************
 *                   Preprocessor Macros
 *****************************************************/

/* UART Driver Baud Rate */
#define USART_BAUDRATE 9600

/*******************************************************
 *               Function Prototypes
 * ****************************************************/

void UART_init(void);

void UART_sendByte(const u8 data);

u8 UART_receiveByte(void);

void UART_sendString(const u8 *str);

void UART_receiveString( u8 *str);


#endif /* UART_H_ */
