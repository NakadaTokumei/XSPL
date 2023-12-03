#ifndef __XSPL_RCC_HPP__
#define __XSPL_RCC_HPP__

#include "LL/rcc.h"

namespace xspl
{

enum class RCCClockOutput : UINT32
{
    NO_CLK,
    SYSCLK = 4,
    HSICLK,
    HSECLK,
    PLLDIV2,
    PLL2,
    PLL3DIV2,
    XT1EXT,
    PLL3NET  
};

enum class RCCPLLMulFactor : UINT32
{
    PLLx4 = 2,
    PLLx5,
    PLLx6,
    PLLx7,
    PLLx8,
    PLLx9,
    PLLx6_5 = 13
};

enum class RCCAPBPrescaler : UINT32
{
    DIV2 = 4,
    DIV4,
    DIV8,
    DIV16
};

enum class RCCAPBConfig : UINT32
{
    APB1,
    APB2
};

class RCC
{
public:

    /* RCC Clock Control Register Part START */
    template<UINT32 PLLNUM>
    static BOOL 
    isPLLReady() { return static_cast<BOOL>(RCC_reg->CR & xdef::bitShift(25 + (PLLNUM * 2))); }

    static BOOL
    isPLL1Ready() { return isPLLReady<0>(); }
    static BOOL
    isPLL2Ready() { return isPLLReady<1>(); }
    static BOOL
    isPLL3Ready() { return isPLLReady<2>(); }

    template<UINT32 PLLNUM>
    static VOID
    SetPLL(BOOL flag)
    {
        if(flag)
            RCC_reg->CR |= xdef::bitShift(24 + (PLLNUM * 2));
        else
            RCC_reg->CR &= ~(xdef::bitShift(24 + (PLLNUM * 2)));
    }

    static VOID
    PLL1On(VOID) { SetPLL<0>(true); }
    static VOID
    PLL1Off(VOID) { SetPLL<0>(false); }

    static VOID
    PLL2On(VOID) { SetPLL<1>(true); }
    static VOID
    PLL2Off(VOID) { SetPLL<1>(false); }

    static VOID
    PLL3On(VOID) { SetPLL<2>(true); }
    static VOID
    PLL3Off(VOID) { SetPLL<2>(false); }

    static BOOL 
    isHSIReady() { return static_cast<BOOL>(RCC_reg->CR & xdef::bitShift(1)); }

    static BOOL 
    isHSEReady() { return static_cast<BOOL>(RCC_reg->CR & xdef::bitShift(17)); }

    static void
    SetHSI(BOOL flag)
    {
        if(flag)
            RCC_reg->CR |= xdef::bitShift(0);
        else
            RCC_reg->CR &= ~(xdef::bitShift(0));
    }

    static VOID
    SetHSE(BOOL flag)
    {
        if(flag)
            RCC_reg->CR |= xdef::bitShift(16);
        else
            RCC_reg->CR &= ~(xdef::bitShift(16));
    }
    /* RCC Clock Control Register Part END */

    /* RCC Clock Configuration Register Part START */

    static VOID
    SetMCUClkOut(RCCClockOutput clkout)
    {
        BIT_CLEAR(RCC_reg->CFGR, 0x0f, 24);
        BIT_FILL(RCC_reg->CFGR, static_cast<UINT32>(clkout), 24);
    }

    static VOID
    SetPLLMul(RCCPLLMulFactor pllmul)
    {
        BIT_CLEAR(RCC_reg->CFGR, 0x0f, 18);
        BIT_FILL(RCC_reg->CFGR, static_cast<UINT32>(pllmul), 18);
    }

    template<RCCAPBConfig APBCONFIG>
    static VOID
    SetAPBPrescaler(RCCAPBPrescaler presclaer)
    {
        BIT_CLEAR(RCC_reg->CFGR, 0x7, (8 + (static_cast<UINT32>(APBCONFIG) * 3)));
        BIT_FILL(RCC_reg->CFGR, static_cast<UINT32>(presclaer), (8 + (static_cast<UINT32>(APBCONFIG) * 3)));
    }

    /* RCC Clock Configuration Register Part END*/

};

}

#endif