#include "GPIO.h"
#include "RCC.h"
#include "EXTI.h"
#include "NVIC.h"
#include "SYSCFG.h"

static unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                        0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char counter = 0;

void enableInterrupt(){
	EXTI_UnmaskInterrupt(0);
	EXTI_UnmaskInterrupt(1);
}

void disableInterrupt(){
	EXTI_MaskInterrupt(0);
	EXTI_MaskInterrupt(1);
}

void ISR_Increment(void)
{
    counter = (counter == 9) ? 9 : counter + 1;

    EXTI_ClearFlag(0);
}

void ISR_Decrement(void)
{
    counter = (counter == 0) ? 0 : counter - 1;
    EXTI_ClearFlag(1);
}

void displaySevenSegment(unsigned char counter){
	for (unsigned char i = 0; i < 7; i++)
	    {
	        GPIO_WritePin(1, i, (sevenSegHex[counter] & (1 << i)) >> i);
	    }
}

int main(void)
{
	unsigned char localCounter;
    RCC_EnableGPIO(0);
    RCC_EnableGPIO(1);
    GPIO_Init(0, 0, INPUT, PULL_UP);
    GPIO_Init(0, 1, INPUT, PULL_UP);

    for (unsigned char i = 0; i < 7; i++)
    {
        GPIO_Init(1, i, OUTPUT, PUSH_PULL);
    }

    RCC_EnableSYSCFG();
    SYSCFG_ExternalPort(0,0);
    SYSCFG_ExternalPort(0,1);

	EXTI_UnmaskInterrupt(0);
	EXTI_UnmaskInterrupt(1);

	EXTI_FallingTrigger(0);
	EXTI_FallingTrigger(1);

    NVIC_EnableExternal(0);
    NVIC_EnableExternal(1);



    while (1)
    {
    	disableInterrupt();
    	localCounter = counter;
    	enableInterrupt();

    	displaySevenSegment(localCounter);
    }

    return 0;
}
