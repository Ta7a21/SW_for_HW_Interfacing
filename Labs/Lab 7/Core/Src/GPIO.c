#include "GPIO.h"

unsigned int *GPIO_RegisterTable[2][5] = {{GPIOAMODER, GPIOAOTYPER, GPIOAPUPDR, GPIOAIDR, GPIOAODR}, {GPIOBMODER, GPIOBOTYPER, GPIOBPUPDR, GPIOBIDR, GPIOBODR}};

void GPIO_Init(unsigned char PortId, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState)
{
  *GPIO_RegisterTable[PortId][0] &= ~(0x03 << 2 * PinNum);
  *GPIO_RegisterTable[PortId][0] |= PinMode << 2 * PinNum;

  *GPIO_RegisterTable[PortId][1] &= ~(1 << PinNum);
  *GPIO_RegisterTable[PortId][1] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

  *GPIO_RegisterTable[PortId][2] &= ~(0x03 << 2 * PinNum);
  *GPIO_RegisterTable[PortId][2] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
}

unsigned char GPIO_WritePin(unsigned char PortId, unsigned char PinNum,
                            unsigned char Data)
{
  unsigned char result;
  if (((*GPIO_RegisterTable[PortId][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1)
  {
    if (Data)
    {
      *GPIO_RegisterTable[PortId][4] |= (1 << PinNum);
    }
    else
    {
      *GPIO_RegisterTable[PortId][4] &= ~(1 << PinNum);
    }
    result = OK;
  }
  else
  {
    result = NOK;
  }
  return result;
}

unsigned char GPIO_TogglePin(unsigned char PortId, unsigned char PinNum)
{
  unsigned char result;
  if (((*GPIO_RegisterTable[PortId][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1)
  {
    *GPIO_RegisterTable[PortId][4] ^= (1 << PinNum);
    result = OK;
  }
  else
  {
    result = NOK;
  }
  return result;
}

unsigned char GPIO_ReadPin(unsigned char PortId, unsigned char PinNum)
{
  unsigned char data = 0;
  data = (*GPIO_RegisterTable[PortId][3] & (1 << PinNum)) >> PinNum;
  return data;
}
