#include "RCC.h"

void RCC_EnableGPIO(unsigned char PortId){
    RCC_AHB1ENR |= (0x01 << PortId);
}

void RCC_EnableSYSCFG(){
	RCC_APB2ENR |= (0x01 << 14);
}

