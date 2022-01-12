#ifndef INC_USART_H_
#define INC_USART_H_

// Oversampling
#define OVER16 0
#define OVER8 1

// Word size
#define WORD8 0
#define WORD9 1

// Stop bit
#define STOP1 ((unsigned char)0x00)
#define STOP0_5 ((unsigned char)0x01)
#define STOP2 ((unsigned char)0x10)

// Mode
#define TRANSMIT 3
#define RECEIVE 2

#define USART1_BRR DEFINE_REG(0x40011000, 0x08)
#define USART1_CR1 DEFINE_REG(0x40011000, 0x0C)
#define USART1_CR2 DEFINE_REG(0x40011000, 0x10)
#define USART1_DR DEFINE_REG(0x40011000, 0x04)
#define USART1_SR DEFINE_REG(0x40011000, 0x00)

#define USART2_BRR DEFINE_REG(0x40004400, 0x08)
#define USART2_CR1 DEFINE_REG(0x40004400, 0x0C)
#define USART2_CR2 DEFINE_REG(0x40004400, 0x10)
#define USART2_DR DEFINE_REG(0x40004400, 0x04)
#define USART2_SR DEFINE_REG(0x40004400, 0x00)

#define USART6_BRR DEFINE_REG(0x40011400, 0x08)
#define USART6_CR1 DEFINE_REG(0x40011400, 0x0C)
#define USART6_CR2 DEFINE_REG(0x40011400, 0x10)
#define USART6_DR DEFINE_REG(0x40011400, 0x04)
#define USART6_SR DEFINE_REG(0x40011400, 0x00)

void USART_EnableClock();
void USART_Init(unsigned char Mode, unsigned char Stop, unsigned char WordLength, unsigned char Oversampling);
void USART_Transmit(char *str);

#endif /* INC_USART_H_ */
