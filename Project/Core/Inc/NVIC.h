#ifndef INC_NVIC_H_
#define INC_NVIC_H_

#include "main.h"

#define NVIC_ISER(x) DEFINE_REG(0xE000E100, 0x04 * x)

void NVIC_EnableInterruptLine(unsigned char InterruptLine);

#endif /* INC_NVIC_H_ */
