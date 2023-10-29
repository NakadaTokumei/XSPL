#ifndef __LL_GPIO_H__
#define __LL_GPIO_H__

#include "xdef/_macro.h"
#include "xdef/_error.h"

typedef struct
{
    volatile UINT32 CRL;
    volatile UINT32 CRH;
    volatile UINT32 IDR;
    volatile UINT32 ODR;
    volatile UINT32 BSRR;
    volatile UINT32 BRR;
    volatile UINT32 LCKR;
}__GPIO__;


#define GPIO_BASE_MEMORY 0x40010800

#define GPIOA ((__GPIO__*)(GPIO_BASE_MEMORY))           // GPIOA
#define GPIOB ((__GPIO__*)(GPIO_BASE_MEMORY + 0x400))   // GPIOB
#define GPIOC ((__GPIO__*)(GPIO_BASE_MEMORY + 0x800))   // GPIOC
#define GPIOD ((__GPIO__*)(GPIO_BASE_MEMORY + 0xc00))   // GPIOD
#define GPIOE ((__GPIO__*)(GPIO_BASE_MEMORY + 0x1000))  // GPIOE
#define GPIOF ((__GPIO__*)(GPIO_BASE_MEMORY + 0x1400))  // GPIOF
#define GPIOG ((__GPIO__*)(GPIO_BASE_MEMORY + 0x1800))  // GPIOG

#endif