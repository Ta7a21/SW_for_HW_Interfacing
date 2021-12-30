#include "GPIO.h"
#include "RCC.h"
#include "USART.h"

int main(void)
{
    GPIO_EnableClock(0);
    GPIO_Init(0, 2, ALTERNATE_FUN, PUSH_PULL);
    GPIO_AlternateConfig(0, 2, ALTERNATE_USART);

    USART_EnableClock();
    USART_Init(TRANSMIT, STOP1, WORD8, OVER16);

    USART_Transmit("Hello World");

    while (1)
    {
    }

    return 0;
}
