#include "stm32f401cc_interface.h"

void delay(int secs)
{
	while (secs--)
	{
	}
}

void blinkRGB(int color)
{
	GPIOB_ODR &= ~(7 << 5);
	GPIOB_ODR |= color << 5;
}

int main(void)
{
	RCC_AHB1ENR |= 1 << 1;
	GPIOB_MODER |= 21 << (5 * 2);
	GPIOB_MODER &= ~(3 << (3 * 2));
	GPIOB_PUPDR |= (1 << (3 * 2));
	GPIOB_OTYPER &= ~(7 << 5);
	GPIOB_ODR |= 7 << 5;
	int color = 0;

	while (1)
	{
		unsigned int buttonState = (GPIOB_IDR >> 3) & 1;
		delay(1000);
		if (buttonState && !((GPIOB_IDR >> 3) & 1))
		{
			blinkRGB((color) % 8);
			color += 1;
		}
	}
	return 0;
}
