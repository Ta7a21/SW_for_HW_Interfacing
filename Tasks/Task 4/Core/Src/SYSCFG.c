#include "SYSCFG.h"

void SYSCFG_ExternalPort(unsigned char PortNum, unsigned char PinNum){
	if (PortNum>0)
		SYSCFG_EXTICR1 |= (PortNum << 4*PinNum);
	else
		SYSCFG_EXTICR1 &= ~(0x0f << 4*PinNum);
}
