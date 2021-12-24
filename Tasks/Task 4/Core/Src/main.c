#include "GPIO.h"

static unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                        0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char counter = 0;

void ISR_Increment(void)
{
    counter = (counter == 9) ? 0 : counter + 1;

    for (unsigned char i = 0; i < 7; i++)
    {
        GPIO_WritePin(1, i, (sevenSegHex[counter] & (1 << i)) >> i);
    }

    EXTI_PR |= (0x01 << 0);
}

void ISR_Decrement(void)
{
    counter = (counter == 0) ? 9 : counter - 1;

    for (unsigned char i = 0; i < 7; i++)
    {
        GPIO_WritePin(1, i, (sevenSegHex[counter] & (1 << i)) >> i);
    }

    EXTI_PR |= (0x02 << 0);
}

int main(void)
{

    GPIO_EnableClock(0);
    GPIO_EnableClock(1);
    GPIO_Init(0, 0, INPUT, PULL_UP);
    GPIO_Init(0, 1, INPUT, PULL_UP);

    for (unsigned char i = 0; i < 7; i++)
    {
        GPIO_Init(1, i, OUTPUT, PUSH_PULL);
    }

    EXTI_IMR |= (0x03 << 0);
    EXTI_FTSR |= (0x03 << 0);
    NVIC_ISER |= (0x03 << 6);

    for (unsigned char i = 0; i < 7; i++)
    {
        GPIO_WritePin(1, i, (sevenSegHex[counter] & (1 << i)) >> i);
    }

    while (1)
    {
    }

    return 0;
}
