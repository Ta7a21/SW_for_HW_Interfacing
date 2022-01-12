#include "NVIC.h"

void NVIC_EnableInterruptLine(unsigned char InterruptLine)
{
	NVIC_ISER((InterruptLine / 32)) |= (0x01 << (InterruptLine % 32));
}
