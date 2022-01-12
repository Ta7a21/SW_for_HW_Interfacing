#ifndef INC_DMA_H_
#define INC_DMA_H_

#include "main.h"

// Item's size
#define BYTE 0x00
#define HALF_WORD 0x01
#define WORD 0x02

// Interrupt flags
#define TC 0x04
#define HT 0x03
#define TE 0x02
#define DME 0x01
#define FE 0x07

// Transfer mode
#define PERIPHERAL_TO_MEMORY 0x00
#define MEMORY_TO_PERIPHERAL 0x01
#define MEMORY_TO_MEMORY 0x02

// Transfer type
#define SINGLE 0x00
#define INCR4 0x01
#define INCR8 0x02
#define INCR16 0x03

// Pointer mode
#define FIXED 0x00
#define INCREMENTING 0x01

// FIFO Threshold
#define QUARTER_FIFO 0x00
#define HALF_FIFO 0x01
#define THREE_QUARTERS_FIFO 0x02
#define FULL_FIFO 0x03

// Priority Levels
#define LOW 0x00
#define MEDIUM 0x01
#define HIGH 0x02
#define VERY_HIGH 0x03

// Flow controller
#define DMA 0x00
#define PERIPHERAL 0X01

// Registers
#define DMA1_LISR DEFINE_REG(0x40026000, 0x00)
#define DMA1_HISR DEFINE_REG(0x40026000, 0x04)
#define DMA1_LIFCR DEFINE_REG(0x40026000, 0x08)
#define DMA1_HIFCR DEFINE_REG(0x40026000, 0x0C)
#define DMA1_SxCR(x) DEFINE_REG(0x40026000, 0x10 + 0x18 * x)
#define DMA1_SxNDTR(x) DEFINE_REG(0x40026000, 0x14 + 0x18 * x)
#define DMA1_SxPAR(x) DEFINE_REG(0x40026000, 0x18 + 0x18 * x)
#define DMA1_SxM0AR(x) DEFINE_REG(0x40026000, 0x1C + 0x18 * x)
#define DMA1_SxM1AR(x) DEFINE_REG(0x40026000, 0x20 + 0x18 * x)
#define DMA1_SxFCR(x) DEFINE_REG(0x40026000, 0x24 + 0x24 * x)

#define DMA2_LISR DEFINE_REG(0x40026400, 0x00)
#define DMA2_HISR DEFINE_REG(0x40026400, 0x04)
#define DMA2_LIFCR DEFINE_REG(0x40026400, 0x08)
#define DMA2_HIFCR DEFINE_REG(0x40026400, 0x0C)
#define DMA2_SxCR(x) DEFINE_REG(0x40026400, 0x10 + 0x18 * x)
#define DMA2_SxNDTR(x) DEFINE_REG(0x40026400, 0x14 + 0x18 * x)
#define DMA2_SxPAR(x) DEFINE_REG(0x40026400, 0x18 + 0x18 * x)
#define DMA2_SxM0AR(x) DEFINE_REG(0x40026400, 0x1C + 0x18 * x)
#define DMA2_SxM1AR(x) DEFINE_REG(0x40026400, 0x20 + 0x18 * x)
#define DMA2_SxFCR(x) DEFINE_REG(0x40026400, 0x24 + 0x24 * x)

// Functions
void DMA_EnableClock(unsigned char Id);
void DMA_Init(unsigned char Id, unsigned char Stream, unsigned char TransferMode,
				unsigned int *Source, unsigned int *Destination, unsigned int NumOfItems,
				unsigned char ItemSize, unsigned char PointerType, unsigned char TransferType,
				unsigned char PriorityLevel, unsigned char Channel, unsigned char FlowController);
void DMA_ResetConfigs(unsigned char Id, unsigned char Stream);
void DMA_StartTransfer(unsigned char Stream);
unsigned char DMA_StreamEnabled(unsigned char Id, unsigned char Stream);
void DMA_EnableFlag(unsigned char Id, unsigned char Stream, unsigned char Flag);
void DMA_ClearFlags(unsigned char Id, unsigned char Stream);
unsigned char DMA_CheckFlag(unsigned char Id, unsigned char Stream, unsigned char Flag);
void DMA_SetFIFOThreshold(unsigned char Id, unsigned char Stream, unsigned char Threshold);

#endif /* INC_DMA_H_ */
