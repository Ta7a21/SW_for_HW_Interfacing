#include "GPIO.h"
#include "Keypad.h"

static unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                        0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void KeypadCallouts_KeyPressNotification()
{
    unsigned char keypadValue = Keypad_GetKey();

    if (keypadValue > 9)
        return;

    for (unsigned char i = 0; i < 7; i++)
    {
        GPIO_WritePin(0, i, (sevenSegHex[keypadValue] & (1 << i)) >> i);
    }
}

int main(void)
{

    GPIO_EnableClock(0);
    GPIO_EnableClock(1);

    for (unsigned char i = 0; i < 7; i++)
    {
        GPIO_Init(0, i, OUTPUT, PUSH_PULL);
    }

    Keypad_Init();

    while (1)
    {
        Keypad_Manage();
    }

    return 0;
}
