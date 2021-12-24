#include "GPIO.h"

void ISR_LED(void)
{
    GPIOA_ODR ^= (0x01 << 1);
    EXTI_PR |= (0x01 << 0);
}
int main(void)
{

    GPIO_EnableClock(0);
    GPIO_Init(0, 0, INPUT, PULL_UP);
    GPIO_Init(0, 1, OUTPUT, PUSH_PULL);
    RCC_APB2ENR |= (0x01 << 14);
    SYSCFG_EXTICR1 &= ~(0x0f << 0);
    EXTI_IMR |= (0x01 << 0);
    EXTI_FTSR |= (0x01 << 0);
    NVIC_ISER |= (0x01 << 6);

    while (1)
    {
    }

    return 0;
}
