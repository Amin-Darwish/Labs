/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 29-10-2022            */
/*          Version: 1.0                */
/*          Module: BIT_math            */
/****************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#define SET_BIT(Var , BitNo)       Var = (Var | (1<<BitNo)) 
#define TOGGLE_BIT(Var , BitNo)    Var = (Var ^ (1<<BitNo))
#define CLEAR_BIT(Var , BitNo)     Var = (Var & ~(1<<BitNo))
#define GET_BIT(Var , BitNo)      (Var>>BitNo & 1)

#endif