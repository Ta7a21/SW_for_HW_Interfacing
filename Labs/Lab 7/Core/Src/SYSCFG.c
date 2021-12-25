#include "SYSCFG.h"

void SYSCFG_ExternalPort(unsigned char PortNum, unsigned char PinNum){
	SYSCFG_EXTICR1 &= ~((0x0f-PortNum) << 4*PinNum);
}
