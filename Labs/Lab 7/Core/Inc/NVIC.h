/*
 * NVIC.h
 *
 *  Created on: Dec 25, 2021
 *      Author: amael
 */

#ifndef INC_NVIC_H_
#define INC_NVIC_H_

#include "main.h"


#define NVIC_ISER0 DEFINE_REG(0xE000E100, 0x00)

void NVIC_EnableExternal(unsigned char InterruptLine);


#endif /* INC_NVIC_H_ */
