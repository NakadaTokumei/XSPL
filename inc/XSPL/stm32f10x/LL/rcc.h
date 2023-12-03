#ifndef __LL_RCC_H__
#define __LL_RCC_H__

#include "xdef/_def.h"

typedef struct 
{
    volatile UINT32 CR;
    volatile UINT32 CFGR;
    volatile UINT32 CIR;
    volatile UINT32 APB2RSTR;
    volatile UINT32 APB1RSTR;
    volatile UINT32 AHBENR;
    volatile UINT32 APB2ENR;
    volatile UINT32 APB1ENR;
    volatile UINT32 BDCR;
    volatile UINT32 CSR;
}__RCC__;

#define RCC_reg ((__RCC__*)(0x40020800))

#endif