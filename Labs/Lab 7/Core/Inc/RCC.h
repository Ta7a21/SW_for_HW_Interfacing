/*
 * RCC.h
 *
 *  Created on: Dec 25, 2021
 *      Author: amael
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "main.h"

#define RCC_AHB1ENR DEFINE_REG(0x40023800, 0x30)
#define RCC_APB2ENR DEFINE_REG(0x40023800, 0x44)

void RCC_EnableGPIO(unsigned char PortId);

void RCC_EnableSYSCFG();

#endif /* INC_RCC_H_ */
