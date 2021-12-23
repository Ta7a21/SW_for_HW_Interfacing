#ifndef GPIO_H
#define GPIO_H

#include "stm32f401xc.h"

// Result Status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

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

#define DEFINE_REG(PORT_ID, REG_ID) (*(unsigned int *)(PORT_ID + REG_ID))

#define RCC_AHB1ENR DEFINE_REG(0x40023800, 0x30)
#define RCC_APB2ENR DEFINE_REG(0x40023800, 0x44)

#define GPIOA_MODER DEFINE_REG(0x40020000, 0x00)
#define GPIOA_OTYPER DEFINE_REG(0x40020000, 0x04)
#define GPIOA_PUPDR DEFINE_REG(0x40020000, 0x0C)
#define GPIOA_IDR DEFINE_REG(0x40020000, 0x10)
#define GPIOA_ODR DEFINE_REG(0x40020000, 0x14)

#define GPIOB_MODER DEFINE_REG(0x40020400, 0x00)
#define GPIOB_OTYPER DEFINE_REG(0x40020400, 0x04)
#define GPIOB_PUPDR DEFINE_REG(0x40020400, 0x0C)
#define GPIOB_IDR DEFINE_REG(0x40020400, 0x10)
#define GPIOB_ODR DEFINE_REG(0x40020400, 0x14)

#define SYSCFG_EXTICR1 DEFINE_REG(0x40013800, 0x08)
#define EXTI_IMR DEFINE_REG(0x40013C00, 0x00)
#define EXTI_RTSR DEFINE_REG(0x40013C00, 0x08)
#define EXTI_FTSR DEFINE_REG(0x40013C00, 0x0C)
#define EXTI_PR DEFINE_REG(0x40013C00, 0x14)

#define NVIC_ISER DEFINE_REG(0xE000E100, 0x00)

#define REG(PORT_ID, REG_ID) ((unsigned int *)(PORT_ID + REG_ID))

#define GPIOAMODER REG(0x40020000, 0x00)
#define GPIOAOTYPER REG(0x40020000, 0x04)
#define GPIOAPUPDR REG(0x40020000, 0x0C)
#define GPIOAIDR REG(0x40020000, 0x10)
#define GPIOAODR REG(0x40020000, 0x14)

#define GPIOBMODER REG(0x40020400, 0x00)
#define GPIOBOTYPER REG(0x40020400, 0x04)
#define GPIOBPUPDR REG(0x40020400, 0x0C)
#define GPIOBIDR REG(0x40020400, 0x10)
#define GPIOBODR REG(0x40020400, 0x14)

void GPIO_EnableClock(unsigned char PortId);

void GPIO_Init(unsigned char PortId, unsigned char PinNum, unsigned char PinDir,
               unsigned char DefaultState);
unsigned char GPIO_WritePin(unsigned char PortId, unsigned char PinNum,
                            unsigned char Data);

unsigned char GPIO_ReadPin(unsigned char PortId, unsigned char PinNum);

#endif /* GPIO_H */
