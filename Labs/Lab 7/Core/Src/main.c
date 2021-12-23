#include "GPIO.h"

void delay(int seconds)
{
    while (seconds--)
    {
    }
}

void ISR_LED(void)
{
    GPIOA_ODR ^= (1 << 1);
    EXTI_PR |= (1 << 0);
}
int main(void)
{

    GPIO_EnableClock(0);
    GPIO_Init(0, 0, INPUT, PULL_UP);
    GPIO_Init(0, 1, OUTPUT, PUSH_PULL);
    RCC_APB2ENR |= (1 << 14);
    SYSCFG_EXTICR1 &= ~(1 << 0);
    EXTI_IMR |= (1 << 0);
    EXTI_FTSR |= (1 << 0);
    NVIC_ISER |= (1 << 6);

    while (1)
    {
    }

    return 0;
}
