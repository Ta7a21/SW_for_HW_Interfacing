#include "NVIC.h"

void NVIC_EnableExternal(unsigned char InterruptLine){
	NVIC_ISER0 |= ((0x01<<InterruptLine) << 6);
}
