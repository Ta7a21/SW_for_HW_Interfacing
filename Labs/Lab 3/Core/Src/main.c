#include "stm32f401cc_interface.h"

void delay(int seconds)
{
    while (seconds--)
    {
    }
}

int main(void)
{
    RCC_AHB1ENR |= (0x01 << 0);
    GPIOA_MODER |= (0x01 << 0);
    GPIOA_OTYPER &= ~(0x01 << 0);
    while (1)
    {
        GPIOA_ODR &= ~(1 << 0);
        delay(1000000);
        GPIOA_ODR |= (1 << 0);
        delay(1000000);
    }
    return 0;
}
