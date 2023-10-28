#include "XSPL/stm32f10x/gpio.hpp"

template<xspl::GPIOType T>
using CPP_GPIO = xspl::GPIO<T>;

int main(void)
{
    CPP_GPIO<xspl::GPIOType::TYPE_E>::SetMode(1, xspl::GPIOMode::OUTPUT_HIGH);
    CPP_GPIO<xspl::GPIOType::TYPE_E>::SetOutputConfig(1, xspl::GPIOOutputConfig::PUSH_PULL);
    CPP_GPIO<xspl::GPIOType::TYPE_E>::SetMode(2, xspl::GPIOMode::OUTPUT_NORMAL);
    CPP_GPIO<xspl::GPIOType::TYPE_E>::SetOutputConfig(1, xspl::GPIOOutputConfig::PUSH_PULL);
    CPP_GPIO<xspl::GPIOType::TYPE_E>::Set(1);
    CPP_GPIO<xspl::GPIOType::TYPE_E>::Reset(1);
}