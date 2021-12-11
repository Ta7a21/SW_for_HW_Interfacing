#include "Keypad.h"
#include "GPIO.h"
#include "stm32f401cc_interface.h"

void delay30ms()
{
    for (unsigned int i = 0; i < 30000; i++)
    {
    }
}

static unsigned char keypadValue;
static unsigned char keypadState = RELEASED;
static unsigned char keypadMatrix[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};

void Keypad_Init()
{
    for (unsigned char i = 0; i < 3; i++)
    {
        GPIO_Init('B', i, OUTPUT, PUSH_PULL);
    }
    for (unsigned char i = 3; i < 7; i++)
    {
        GPIO_Init('B', i, INPUT, PULL_UP);
    }
}

void Keypad_Manage()
{
    if (keypadState == RELEASED)
    {
        for (unsigned char i = 0; i < 3; i++)
        {
            GPIO_WritePin('B', i % 3, 0);
            GPIO_WritePin('B', (i + 1) % 3, 1);
            GPIO_WritePin('B', (i + 2) % 3, 1);
            for (unsigned char j = 3; j < 7; j++)
            {
                if (GPIO_ReadPin('B', j) == 0)
                {
                    delay30ms();
                    if (GPIO_ReadPin('B', j) == 0)
                    {
                        keypadState = PRESSED;
                        keypadValue = keypadMatrix[j - 3][i];
                        KeypadCallouts_KeyPressNotification();
                    }
                }
            }
        }
    }
}

unsigned char Keypad_GetKey()
{
    keypadState = RELEASED;
    return keypadValue;
}
