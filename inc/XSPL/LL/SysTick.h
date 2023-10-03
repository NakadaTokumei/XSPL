#ifndef __LL_SYSTICK_H__
#define __LL_SYSTICk_H__

#include "macro.h"

typedef struct
{
    _IO UINT32 CTRL;
    _IO UINT32 LOAD;
    _IO UINT32 VAL;
    _IO UINT32 CALIB;
}SYSTICkType, *PSYSTICKType;

#define SYSTICK ((_IO PSYSTICKType)(0xe000e010))

#endif