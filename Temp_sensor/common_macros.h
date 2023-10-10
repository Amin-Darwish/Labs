/*********************************************************
 *
 * Module: Common - Macros
 *
 *File Name: commen_macros.h
 *
 *  Description: Commonly used Macros
 *
 *******************************************************/

#ifndef COMMON_MACROS
#define COMMON_MACROS

/* Set a bit in any Register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a bit in any Register */
#define CLEAR_BIT(REG,BIT) (REG&=~(1<<BIT))

/* Toggle a bit in any Register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the REG value with a specific NUM of rotates */
#define ROR(REG,NUM) ( REG=(REG>>NUM) | (REG>>(8-NUM)) )

/* Rotate left the REG value with a specific NUM of rotates */
#define RORL(REG,NUM) ( REG=(REG<<NUM) | (REG<<(8-NUM)) )

/* Check if a specific bit is set (1) in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) (REG & (1<<BIT))

/* Check if a specific bit is cleared (0) in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))

#endif
