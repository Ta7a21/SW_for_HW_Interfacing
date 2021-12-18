#include "GPIO.h"
#include "Seven_Segment.h"
#include "stm32f401cc_interface.h"

void delay(unsigned int time)
{
    while (time--)
    {
    }
}

int main(void)
{
    // Initialize 7 pins as output (push pull)
    GPIO_Init('A', 4, OUTPUT, PUSH_PULL);
    GPIO_Init('A', 5, OUTPUT, PUSH_PULL);
    GPIO_Init('A', 6, OUTPUT, PUSH_PULL);
    GPIO_Init('A', 7, OUTPUT, PUSH_PULL);
    GPIO_Init('A', 8, OUTPUT, PUSH_PULL);
    GPIO_Init('A', 9, OUTPUT, PUSH_PULL);
    GPIO_Init('A', 10, OUTPUT, PUSH_PULL);

    // Start with number zero
    unsigned int number = 0;

    while (1)
    {
        // Exclude any values bigger than nine
        changeSevenSegment((number++) % 10);
        delay(1500000);
    }
    return 0;
}
