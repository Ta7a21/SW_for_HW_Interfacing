#ifndef KEYPAD_H
#define KEYPAD_H

#include "stm32f401xc.h"

#define RELEASED 1
#define PRESSED 0

void Keypad_Init();
void Keypad_Manage();
void KeypadCallouts_KeyPressNotification();
unsigned char Keypad_GetKey();

#endif /* KEYPAD_H */
