#ifndef GPIO_H
#define GPIO_H

#include "main.h"

// Result Status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

#define ALTERNATE_USART 0x07

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

#define GPIOA_MODER DEFINE_REG(0x40020000, 0x00)
#define GPIOA_OTYPER DEFINE_REG(0x40020000, 0x04)
#define GPIOA_PUPDR DEFINE_REG(0x40020000, 0x0C)
#define GPIOA_IDR DEFINE_REG(0x40020000, 0x10)
#define GPIOA_ODR DEFINE_REG(0x40020000, 0x14)
#define GPIOA_AFRL DEFINE_REG(0x40020000, 0x20)
#define GPIOA_AFRH DEFINE_REG(0x40020000, 0x24)

#define GPIOB_MODER DEFINE_REG(0x40020400, 0x00)
#define GPIOB_OTYPER DEFINE_REG(0x40020400, 0x04)
#define GPIOB_PUPDR DEFINE_REG(0x40020400, 0x0C)
#define GPIOB_IDR DEFINE_REG(0x40020400, 0x10)
#define GPIOB_ODR DEFINE_REG(0x40020400, 0x14)
#define GPIOB_AFRL DEFINE_REG(0x40020400, 0x20)
#define GPIOB_AFRH DEFINE_REG(0x40020400, 0x24)

#define GPIOAMODER REG(0x40020000, 0x00)
#define GPIOAOTYPER REG(0x40020000, 0x04)
#define GPIOAPUPDR REG(0x40020000, 0x0C)
#define GPIOAIDR REG(0x40020000, 0x10)
#define GPIOAODR REG(0x40020000, 0x14)
#define GPIOAAFRL REG(0x40020000, 0x20)
#define GPIOAAFRH REG(0x40020000, 0x24)

#define GPIOBMODER REG(0x40020400, 0x00)
#define GPIOBOTYPER REG(0x40020400, 0x04)
#define GPIOBPUPDR REG(0x40020400, 0x0C)
#define GPIOBIDR REG(0x40020400, 0x10)
#define GPIOBODR REG(0x40020400, 0x14)
#define GPIOBAFRL REG(0x40020000, 0x20)
#define GPIOBAFRH REG(0x40020000, 0x24)

void GPIO_EnableClock(unsigned char PortId);

void GPIO_Init(unsigned char PortId, unsigned char PinNum, unsigned char PinDir,
               unsigned char DefaultState);

void GPIO_AlternateConfig(unsigned char PortId, unsigned char PinNum, unsigned char Function);

unsigned char GPIO_WritePin(unsigned char PortId, unsigned char PinNum,
                            unsigned char Data);

unsigned char GPIO_TogglePin(unsigned char PortId, unsigned char PinNum);

unsigned char GPIO_ReadPin(unsigned char PortId, unsigned char PinNum);

#endif /* GPIO_H */
