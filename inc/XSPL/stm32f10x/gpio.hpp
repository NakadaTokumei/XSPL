#ifndef __XSPL_GPIO_HPP__
#define __XSPL_GPIO_HPP__

#include "LL/gpio.h"

namespace xspl
{

enum class GPIOType : UINT32
{
    TYPE_A,
    TYPE_B,
    TYPE_C,
    TYPE_D,
    TYPE_E,
    TYPE_F,
    TYPE_G,
};

enum class GPIOMode : UINT32
{
    INPUT,
    OUTPUT_NORMAL,
    OUTPUT_SLOW,
    OUTPUT_HIGH
};

enum class GPIOInputConfig : UINT32
{
    ANLOG,
    FLOATING_POINT,
    PULL_UP_DOWN,
    RESERVED
};

enum class GPIOOutputConfig : UINT32
{
    PUSH_PULL,
    OPEN_DRAIN,
    ALTERNATE_PUSH_PULL,
    ALTERNATE_OPEN_DRAIN
};

static inline constexpr UINT32 
_gpioOffset(GPIOType type)
{
    return (static_cast<UINT32>(type) * 0x400);
}
 
static inline constexpr __GPIO__*
_getGPIOMemory(GPIOType gpioType)
{
    return ((__GPIO__*)(
        GPIO_BASE_MEMORY + 
        _gpioOffset(gpioType)
    ));
}

template<GPIOType T>
class GPIO
{
public:
    static void SetMode(UINT32 pinNum, GPIOMode mode)
    {
        // High
        if(pinNum > 7)
        {
            pinNum -= 8;
            _getGPIOMemory(T)->CRH &= ~((0x03) << (pinNum * 2));
            _getGPIOMemory(T)->CRH |= (static_cast<UINT32>(mode) << (pinNum * 2));
        }
        // Low
        else
        {
            _getGPIOMemory(T)->CRL &= ~((0x03) << (pinNum * 2));
            _getGPIOMemory(T)->CRL |= (static_cast<UINT32>(mode) << (pinNum * 2));
        }
    }

    static void SetInputConfig(UINT32 pinNum, GPIOInputConfig config)
    {
        // High
        if(pinNum > 7)
        {
            pinNum -= 8;
            _getGPIOMemory(T)->CRH &= ~((0x03) << (pinNum * 2 + 1));
            _getGPIOMemory(T)->CRH |= (static_cast<UINT32>(config) << (pinNum * 2 + 1));
        }
        // Low
        else
        {
            _getGPIOMemory(T)->CRL &= ~((0x03) << (pinNum * 2 + 1));
            _getGPIOMemory(T)->CRL |= (static_cast<UINT32>(config) << (pinNum * 2 + 1));
        }
    }

    static void SetOutputConfig(UINT32 pinNum, GPIOOutputConfig config)
    {
        // High
        if(pinNum > 7)
        {
            pinNum -= 8;
            _getGPIOMemory(T)->CRH &= ~((0x03) << (pinNum * 2 + 1));
            _getGPIOMemory(T)->CRH |= (static_cast<UINT32>(config) << (pinNum * 2 + 1));
        }
        // Low
        else
        {
            _getGPIOMemory(T)->CRL &= ~((0x03) << (pinNum * 2 + 1));
            _getGPIOMemory(T)->CRL |= (static_cast<UINT32>(config) << (pinNum * 2 + 1));
        }
    }

    static void Set(UINT32 pinNum)
    {
        _getGPIOMemory(T)->ODR |= pinNum;
    }

    static void Reset(UINT32 pinNum)
    {
        _getGPIOMemory(T)->BRR |= pinNum;
    }

    static bool Input(UINT32 pinNum)
    {
        return static_cast<bool>(_getGPIOMemory(T)->IDR & (0x01 << pinNum));
    }
};

};

#endif