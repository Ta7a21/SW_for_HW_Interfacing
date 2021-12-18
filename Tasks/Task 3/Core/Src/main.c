#include "GPIO.h"
#include "stm32f401cc_interface.h"

void delay(unsigned int time)
{
    while (time--)
    {
    }
}

void changeRGB(unsigned int color)
{
    // Clear 5,6,7 pins
    GPIO_WRITE_PIN('B', 5, 0);
    GPIO_WRITE_PIN('B', 6, 0);
    GPIO_WRITE_PIN('B', 7, 0);
    // Set 5,6,7 pins with color number 0-7
    // Stop colors at 7 and repeat from 0 ==> 111
    GPIO_WRITE_PIN('B', 5, color & 1);
    GPIO_WRITE_PIN('B', 6, color & 2);
    GPIO_WRITE_PIN('B', 7, color & 4);
}

int main(void)
{
    // Enable GPIOB
    GPIO_INIT('B');
    // Set output pins 5,6,7 ==> 010101
    GPIO_DIR('B', 5, OUTPUT);
    GPIO_DIR('B', 6, OUTPUT);
    GPIO_DIR('B', 7, OUTPUT);
    // Set input pin 3 ==> 00
    GPIO_DIR('B', 3, INPUT);
    // Set input mode for pin 3 (pull-up resistor)
    GPIO_INPUT_MODE('B', 3, PULL_UP);
    // Set output mode for pins 5,6,7  (push-pull)
    GPIO_OUTPUT_MODE('B', 5, PUSH_PULL);
    GPIO_OUTPUT_MODE('B', 6, PUSH_PULL);
    GPIO_OUTPUT_MODE('B', 7, PUSH_PULL);
    // Start colors from red ==> 001
    int color = 1;

    while (1)
    {
        // Save button state of pin 3
        unsigned int buttonState = GPIO_READ_PIN('B', 3);
        // Wait for the user to press the button
        delay(1000);
        // Check if the button was pressed (state==0)
        if (buttonState && !(GPIO_READ_PIN('B', 3)))
        {
            changeRGB(color % 8);
            color += 1;
        }
    }
    return 0;
}
