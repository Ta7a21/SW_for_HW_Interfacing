#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "main.h"

#define RCC_AHB1ENR DEFINE_REG(0x40023800, 0x30)
#define RCC_APB1ENR DEFINE_REG(0x40023800, 0x40)
#define RCC_APB2ENR DEFINE_REG(0x40023800, 0x44)

#endif /* INC_RCC_H_ */
