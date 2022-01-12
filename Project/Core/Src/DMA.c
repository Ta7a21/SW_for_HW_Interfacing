#include "DMA.h"
#include "RCC.h"

void DMA_EnableClock(unsigned char Id)
{
	RCC_AHB1ENR |= (0x01 << (20 + Id));
}

void DMA_Init(unsigned char Id, unsigned char Stream, unsigned char TransferMode, 
				unsigned int *Source, unsigned int *Destination, unsigned int NumOfItems, 
				unsigned char ItemSize, unsigned char PointerType, unsigned char TransferType, 
				unsigned char PriorityLevel, unsigned char Channel, unsigned char FlowController)
{
	DMA_ResetConfigs(Id, Stream);
	switch (Id)
	{
	case 1:
		DMA1_SxCR(Stream) |= (Channel << 25);
		DMA1_SxCR(Stream) |= (TransferMode << 6);
		DMA1_SxPAR(Stream) = (unsigned int)Source;
		DMA1_SxM0AR(Stream) = (unsigned int)Destination;
		DMA1_SxNDTR(Stream) = NumOfItems;
		DMA1_SxCR(Stream) |= (ItemSize << 11);
		DMA1_SxCR(Stream) |= (ItemSize << 13);
		DMA1_SxCR(Stream) |= (TransferType << 21);
		DMA1_SxCR(Stream) |= (TransferType << 23);
		DMA1_SxCR(Stream) |= (PointerType << 9);
		DMA1_SxCR(Stream) |= (PointerType << 10);
		DMA1_SxCR(Stream) |= (PriorityLevel << 16);
		DMA1_SxCR(Stream) |= (FlowController << 5);
		break;
	case 2:
		DMA2_SxCR(Stream) |= (Channel << 25);
		DMA2_SxCR(Stream) |= (TransferMode << 6);
		DMA2_SxPAR(Stream) = (unsigned int)Source;
		DMA2_SxM0AR(Stream) = (unsigned int)Destination;
		DMA2_SxNDTR(Stream) = NumOfItems;
		DMA2_SxCR(Stream) |= (ItemSize << 11);
		DMA2_SxCR(Stream) |= (ItemSize << 13);
		DMA2_SxCR(Stream) |= (TransferType << 21);
		DMA2_SxCR(Stream) |= (TransferType << 23);
		DMA2_SxCR(Stream) |= (PointerType << 9);
		DMA2_SxCR(Stream) |= (PointerType << 10);
		DMA2_SxCR(Stream) |= (PriorityLevel << 16);
		DMA2_SxCR(Stream) |= (FlowController << 5);
		break;
	}
}

void DMA_ResetConfigs(unsigned char Id, unsigned char Stream){
	switch(Id){
	case 1:
		DMA1_SxCR(Stream) = 0x00000000;
		DMA1_SxNDTR(Stream) = 0x00000000;
		DMA1_SxPAR(Stream) = 0x00000000;
		DMA1_SxM0AR(Stream) = 0x00000000;
		DMA1_SxFCR(Stream) =  0x00000021;
		break;
	case 2:
		DMA2_SxCR(Stream) = 0x00000000;
		DMA2_SxNDTR(Stream) = 0x00000000;
		DMA2_SxPAR(Stream) = 0x00000000;
		DMA2_SxM0AR(Stream) = 0x00000000;
		DMA2_SxFCR(Stream) =  0x00000021;
		break;
	}

}

void DMA_SetFIFOThreshold(unsigned char Id, unsigned char Stream, unsigned char Threshold){
	switch(Id){
	case 1:
		DMA1_SxFCR(Stream) |= (0x01 << 2);
		DMA1_SxFCR(Stream) |= (Threshold);
		break;
	case 2:
		DMA2_SxFCR(Stream) |= (0x01 << 2);
		DMA2_SxFCR(Stream) |= (Threshold);
		break;
	}
}


void DMA_StartTransfer(unsigned char Stream)
{
	DMA_ClearFlags(2, Stream);
	DMA2_SxCR(Stream) |= 0x01;
}

unsigned char DMA_StreamEnabled(unsigned char Id, unsigned char Stream)
{
	switch (Id)
	{
	case 1:
		return (DMA1_SxCR(Stream) & 1);
		break;
	case 2:
		return (DMA2_SxCR(Stream) & 1);
		break;
	}

	return 0;
}

void DMA_EnableFlag(unsigned char Id, unsigned char Stream, unsigned char Flag)
{
	switch (Id)
	{
	case 1:
		if (Flag == FE)
			DMA1_SxFCR(Stream) |= (0x01 << Flag);
		else
			DMA1_SxCR(Stream) |= (0x01 << Flag);
		break;
	case 2:
		if (Flag == FE)
			DMA2_SxFCR(Stream) |= (0x01 << Flag);
		else
			DMA2_SxCR(Stream) |= (0x01 << Flag);
		break;
	}
}

void DMA_ClearFlags(unsigned char Id, unsigned char Stream)
{
	switch (Id)
	{
	case 1:
		if (Stream < 4)
			DMA1_LIFCR = (0x3D << Stream * 6);
		else
			DMA1_HIFCR = (0x3D << Stream * 6);
		break;
	case 2:
		if (Stream < 4)
			DMA2_LIFCR = (0x3D << Stream * 6);
		else
			DMA2_HIFCR = (0x3D << Stream * 6);
		break;
	}
}

unsigned char DMA_CheckFlag(unsigned char Id, unsigned char Stream, unsigned char Flag)
{
	Flag = (Flag == FE) ? 0 : Flag + 1;
	switch (Id)
	{
	case 1:
		if (Stream < 4)
			return ((DMA1_LISR >> (Flag + Stream * 6)) & 1);
		else
			return ((DMA1_HISR >> (Flag + Stream * 6)) & 1);
		break;
	case 2:
		if (Stream < 4)
			return ((DMA2_LISR >> (Flag + Stream * 6)) & 1);
		else
			return ((DMA2_HISR >> (Flag + Stream * 6)) & 1);
		break;
	}

	return 0;
}

void DMA2_Stream0_IRQHandler(void)
{
	DMA2_Callout0();
	DMA_ClearFlags(2, 0);
}
