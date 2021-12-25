#include "EXTI.h"

void EXTI_ClearFlag(unsigned char PinNum){
	EXTI_PR |= (0x01 << PinNum);
}

void EXTI_UnmaskInterrupt(unsigned char PinNum){
	EXTI_IMR |= (0x01 << PinNum);
}

void EXTI_MaskInterrupt(unsigned char PinNum){
	EXTI_IMR &= (0x01 << PinNum);
}

void EXTI_FallingTrigger(unsigned char PinNum){
	EXTI_FTSR |= (0x01 << PinNum);
}

void EXTI_RisisngTrigger(unsigned char PinNum){
	EXTI_RTSR |= (0x01 << PinNum);
}
