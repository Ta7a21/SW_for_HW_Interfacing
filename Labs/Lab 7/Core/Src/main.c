#include "GPIO.h"
#include "RCC.h"
#include "EXTI.h"
#include "NVIC.h"
#include "SYSCFG.h"

void ISR_LED(void)
{
    GPIO_TogglePin(0,1);
    EXTI_ClearFlag(0);
}
int main(void)
{
    RCC_EnableGPIO(0);
    RCC_EnableSYSCFG();

    GPIO_Init(0, 0, INPUT, PULL_UP);
    GPIO_Init(0, 1, OUTPUT, PUSH_PULL);

    SYSCFG_ExternalPort(0,0);

    EXTI_UnmaskInterrupt(0);
    EXTI_FallingTrigger(0);

    NVIC_EnableExternal(0);

    while (1)
    {
    }

    return 0;
}
