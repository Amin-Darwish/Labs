/*****************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: types for AVR
 *
 *
 *****************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/** Boolean Data Type **/
typedef unsigned char bool;

/** Boolean Values */
#ifndef FALSE
#define FALSE   (0u)
#endif

#ifndef TRUE
#define TRUE    (1u)
#endif

#define HIGH    (1u)
#define LOW     (0u)

typedef unsigned char           uint8;            /**                    0 .. 255                   */
typedef signed char             sint8;            /**                   -128 .. +127                */
typedef unsigned short          uint16;           /**                  0 .. 65535                   */
typedef signed short            sint16;           /**               -32768 .. +32767                */
typedef unsigned long           uint32;           /**             0 .. 4,294,967,295                */
typedef signed long             sint32;           /**      -2,147,483,648 to 2,147,483,647          */
typedef unsigned long long      uint64;           /**       0 to 18446744073709551615               */
typedef signed long long        sint64;           /** -9223372036854775808 to 9223372036854775807   */
typedef float                   float32;
typedef double                  float64;

#endif   /** STD_TYPES_H_  */
