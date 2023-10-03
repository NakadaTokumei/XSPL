#ifndef __XSPL_SYSTICK_H__
#define __XSPL_SYSTICk_H__

#include "../error.h"

#include "../LL/SysTick.h"
#include "../object/systick_object.h"

namespace xspl
{

class SysTick : public SystickObject
{
private:
public:
    VOID
    Enable(VOID)
    {
        SYSTICK->CTRL |= 0x01;
    }
    
    VOID
    Disable(VOID)
    {
        SYSTICK->CTRL &= ~(0x01);
    }

    VOID
    EnableIRQ(VOID)
    {
        SYSTICK->CTRL |= (0x02);
    }

    VOID
    DisableIRQ(VOID)
    {
        SYSTICK->CTRL &= ~(0x02);
    }

    VOID
    SetClockSource(
        SysTickClkSource clkSource
    )
    {
        SYSTICK->CTRL &= ~(0x04);
        SYSTICK->CTRL |= (static_cast<UINT32>(clkSource) << 2);
    }
    
    UINT32
    GetCurrentValue(VOID)
    {
        return SYSTICK->VAL;
    }

    VOID
    SetReloadCount(
        UINT32 reloadCount
    )
    {
        SYSTICK->LOAD = (reloadCount & 0x00ffffff);
    }
};

}
#endif