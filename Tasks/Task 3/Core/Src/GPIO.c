#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

void GPIO_INIT(char PORT)
{
    switch (PORT)
    {
    case ('A'):
        RCC_AHB1ENR |= (0x01 << 0);
        break;
    case ('B'):
        RCC_AHB1ENR |= (0x01 << 1);

        break;
    }
}

void GPIO_DIR(char PORT, unsigned int PIN_NO, unsigned int PIN_DIR)
{
    switch (PORT)
    {
    case ('A'):
        switch (PIN_DIR)
        {
        case (INPUT):
            GPIOA_MODER &= ~(0x03 << 2 * PIN_NO);
            break;
        case (OUTPUT):
            GPIOA_MODER |= (0x01 << 2 * PIN_NO);
            break;
        case (ALTERNATE_FUN):
            GPIOA_MODER |= (0x02 << 2 * PIN_NO);
            break;
        case (ANALOG):
            GPIOA_MODER |= (0x03 << 2 * PIN_NO);
            break;
        }
        break;
    case ('B'):
        switch (PIN_DIR)
        {
        case (INPUT):
            GPIOB_MODER &= ~(0x03 << 2 * PIN_NO);
            break;
        case (OUTPUT):
            GPIOB_MODER |= (0x01 << 2 * PIN_NO);
            break;
        case (ALTERNATE_FUN):
            GPIOB_MODER |= (0x02 << 2 * PIN_NO);
            break;
        case (ANALOG):
            GPIOB_MODER |= (0x03 << 2 * PIN_NO);
            break;
        }
        break;
    }
}

void GPIO_OUTPUT_MODE(char PORT, unsigned int PIN_NO, unsigned int MODE)
{
    switch (PORT)
    {
    case ('A'):
        switch (MODE)
        {
        case (PUSH_PULL):
            GPIOA_OTYPER &= ~(0x01 << PIN_NO);
            break;
        case (OPEN_DRAIN):
            GPIOA_OTYPER |= (0x01 << PIN_NO);
            break;
        }
        break;
    case ('B'):
        switch (MODE)
        {
        case (PUSH_PULL):
            GPIOB_OTYPER &= ~(0x01 << PIN_NO);
            break;
        case (OPEN_DRAIN):
            GPIOB_OTYPER |= (0x01 << PIN_NO);
            break;
        }
        break;
    }
}

void GPIO_INPUT_MODE(char PORT, unsigned int PIN_NO, unsigned int MODE)
{
    switch (PORT)
    {
    case ('A'):
        switch (MODE)
        {
        case (PULL_UP):
            GPIOA_PUPDR |= (0x01 << 2 * PIN_NO);
            break;
        case (PULL_DOWN):
            GPIOA_PUPDR |= (0x02 << 2 * PIN_NO);
            break;
        }
        break;
    case ('B'):
        switch (MODE)
        {
        case (PULL_UP):
            GPIOB_PUPDR |= (0x01 << 2 * PIN_NO);
            break;
        case (PULL_DOWN):
            GPIOB_PUPDR |= (0x02 << 2 * PIN_NO);
            break;
        }
        break;
    }
}

unsigned char GPIO_WRITE_PIN(char PORT, unsigned int PIN_NO, unsigned int DATA)
{
    unsigned char result;
    switch (PORT)
    {
    case ('A'):
        if ((GPIOA_MODER >> 2 * PIN_NO) & 1)
        {
            if (DATA)
            {
                GPIOA_ODR |= (1 << PIN_NO);
            }
            else
            {
                GPIOA_ODR &= ~(1 << PIN_NO);
            }
            result = OK;
        }
        else
        {
            result = NOK;
        }
        break;
    case ('B'):
        if ((GPIOB_MODER >> 2 * PIN_NO) & 1)
        {
            if (DATA)
            {
                GPIOB_ODR |= (1 << PIN_NO);
            }
            else
            {
                GPIOB_ODR &= ~(1 << PIN_NO);
            }
            result = OK;
        }
        else
        {
            result = NOK;
        }

        break;
    }

    return result;
}

unsigned int GPIO_READ_PIN(char PORT, unsigned int PIN_NO)
{
    unsigned int result;
    switch (PORT)
    {
    case ('A'):
        if (!((GPIOA_MODER >> 2 * PIN_NO) & 1))
        {
            result = (GPIOA_IDR >> PIN_NO) & 1;
        }
        else
        {
            result = 0;
        }
        break;
    case ('B'):
        if (!((GPIOB_MODER >> 2 * PIN_NO) & 1))
        {
            result = (GPIOB_IDR >> PIN_NO) & 1;
        }
        else
        {
            result = 0;
        }

        break;
    }

    return result;
}
