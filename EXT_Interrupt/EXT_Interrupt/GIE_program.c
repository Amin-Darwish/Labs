/******************************************/
/******************************************/
/*******   Author:   Amin Darwish  ********/
/*******   Layer        MCAL       ********/
/*******   Module:      GIE     ********/
/*******   Version:     1.0        ********/
/******************************************/                               
/******************************************/

#include "GIE_interface.h"
#include "GIE_reg.h"

#include "STD_types.h"
#include "BIT_math.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG, SREG_I);
}
void GIE_voidDisable(void)
{
    CLEAR_BIT(SREG, SREG_I);
}



