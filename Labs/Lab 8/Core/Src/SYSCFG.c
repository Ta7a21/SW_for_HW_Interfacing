#include "SYSCFG.h"
#include "RCC.h"

void SYSCFG_EnableClock()
{
	RCC_APB2ENR |= (0x01 << 14);
}

void SYSCFG_ExternalPort(unsigned char PortNum, unsigned char PinNum){
	if (PortNum>0)
		SYSCFG_EXTICR1 |= (PortNum << 4*PinNum);
	else
		SYSCFG_EXTICR1 &= ~(0x0f << 4*PinNum);
}
