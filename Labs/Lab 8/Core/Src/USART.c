#include "USART.h"
#include "RCC.h"

void USART_EnableClock()
{
    RCC_APB1ENR |= (0x01 << 17);
}

void USART_Init(unsigned char Mode, unsigned char Stop, unsigned char WordLength, unsigned char Oversampling)
{
    // Enable USART
    USART2_CR1 |= (1 << 13);
    // Baud rate = 9600
    // From equation, 16MHz / 16 * 9600 = 104.16
    // 104 = 0x68
    // .16 * 16 = 2.6 = 0x003 to keep the value after sampling by 16
    // DIV = 0x683
    USART2_BRR = 0x683;
    USART2_CR1 |= (0x01 << Mode);
    USART2_CR1 |= (WordLength << 12);
    USART2_CR1 |= (Oversampling << 15);
    USART2_CR2 |= (Stop << 12);
}

void USART_Transmit(char *str)
{
    while (*str != '\0')
    {
        while (((USART2_SR >> 6) & 1))
        {
            USART2_DR = *str;
            str++;
        }
    }
}
