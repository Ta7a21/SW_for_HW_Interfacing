/*
 * EXTI.h
 *
 *  Created on: Dec 25, 2021
 *      Author: amael
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "main.h"

#define EXTI_IMR DEFINE_REG(0x40013C00, 0x00)
#define EXTI_RTSR DEFINE_REG(0x40013C00, 0x08)
#define EXTI_FTSR DEFINE_REG(0x40013C00, 0x0C)
#define EXTI_PR DEFINE_REG(0x40013C00, 0x14)

void EXTI_ClearFlag(unsigned char PinNum);

void EXTI_UnmaskInterrupt(unsigned char PinNum);

void EXTI_MaskInterrupt(unsigned char PinNum);

void EXTI_FallingTrigger(unsigned char PinNum);

void EXTI_RisisngTrigger(unsigned char PinNum);


#endif /* INC_EXTI_H_ */
