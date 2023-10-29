#include "XSPL/stm32f10x/gpio.hpp"

template<xspl::GPIOType T>
using CPP_GPIO = xspl::GPIO<T>;
using CPP_GPIOE = CPP_GPIO<xspl::GPIOType::TYPE_E>;

int main(void)
{
    CPP_GPIOE::SetMode(1, xspl::GPIOMode::OUTPUT_HIGH);
    CPP_GPIOE::SetOutputConfig(1, xspl::GPIOOutputConfig::PUSH_PULL);
    CPP_GPIOE::SetMode(2, xspl::GPIOMode::INPUT);
    CPP_GPIOE::SetInputConfig(1, xspl::GPIOInputConfig::PULL_UP_DOWN);

    if(CPP_GPIOE::Input(2))
    {
        CPP_GPIOE::Set(1);
    }
    else
    {
        CPP_GPIOE::Reset(1);
    }
}