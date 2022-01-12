#include "DMA.h"
#include "GPIO.h"
#include "NVIC.h"
#include "USART.h"
#include "string.h"
#include "stdio.h"

#define ARRAYSIZE 100
unsigned int sourceArray[ARRAYSIZE];
unsigned int destinationArray[ARRAYSIZE];

void initializeArray(unsigned int *arr, unsigned int size, unsigned int start)
{
	for (int i = 1; i <= size; i++)
	{
		arr[i - 1] = start * i;
	}
}

char *convertIntegerToString(unsigned int num){
	char *str = "";
	sprintf(str, "%d", num);
	return str;
}

void printLastElement(){
	USART_Transmit(strcat("\r\nTransfer Complete! Now last element equals ",
										convertIntegerToString(destinationArray[ARRAYSIZE-1])));
}

void DMA2_Callout0(){
	if(DMA_CheckFlag(2,0,TC)){
		printLastElement();
	}
}

int main(void)
{
	// GPIO initialization
	GPIO_EnableClock(0);
	GPIO_Init(0, 2, ALTERNATE_FUN, PUSH_PULL);
	GPIO_AlternateConfig(0, 2, ALTERNATE_USART);

	// UART initialization
	USART_EnableClock();
	USART_Init(TRANSMIT, STOP1, WORD8, OVER16);

	// Arrays initialization
	initializeArray(sourceArray, ARRAYSIZE, 100);
	initializeArray(destinationArray, ARRAYSIZE, 0);

	// Test last value
	USART_Transmit(strcat("Last element equals ", 
					convertIntegerToString(destinationArray[ARRAYSIZE-1])));

	// DMA initialization
	DMA_EnableClock(2);
	DMA_Init(2, 0, MEMORY_TO_MEMORY, sourceArray, destinationArray,
				ARRAYSIZE, WORD, INCREMENTING, INCR4, VERY_HIGH, 0, DMA);
	DMA_SetFIFOThreshold(2, 0, FULL_FIFO);

	// DMA interrupt initialization
	DMA_EnableFlag(2, 0, TC);
	NVIC_EnableInterruptLine(56);

	// DMA start transfer request
	DMA_StartTransfer(0);

	while (1)
	{
	}

	return 0;
}
