#ifndef INC_SYSCFG_H_
#define INC_SYSCFG_H_

#include "main.h"

#define SYSCFG_EXTICR1 DEFINE_REG(0x40013800, 0x08)

void SYSCFG_EnableClock();

void SYSCFG_ExternalPort(unsigned char PortNum, unsigned char PinNum);

#endif /* INC_SYSCFG_H_ */
