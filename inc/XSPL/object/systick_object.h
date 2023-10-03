#ifndef __XSPL_SYSTICK_OBJECT_H__
#define __XSPL_SYSTICK_OBJECT_H__

#include "../LL/macro.h"

namespace xspl
{

enum class SysTickClkSource : UINT32
{
    SYSTICK_CLOCK_SOURCE_AHB_DIV_8,
    SYSTICK_CLOCk_SOURCE_AHB
};


class SystickObject
{
private:
public:
    VOID
    Enable(VOID)
    {
        __nop;
    }

    VOID
    Disable(VOID)
    {
        __nop;
    }

    VOID
    EnableIRQ(VOID)
    {
        __nop;
    }

    VOID
    DisableIRQ(VOID)
    {
        __nop;
    }

    VOID
    SetClockSource(
        [[maybe_unused]] SysTickClkSource clkSource
    )
    {
        __nop;
    }
    
    [[maybe_unused]] UINT32
    GetCurrentValue(VOID)
    {
        __nop_return;
    }

    VOID
    SetReloadCounter(
        [[maybe_unused]] UINT32 reloadCount
    )
    {
        __nop;
    }
};

};

#endif