#include "Seven_Segment.h"

void changeSevenSegment(unsigned int number)
{
    // Clear all 7 pins
    GPIO_WritePin('A', 4, 0);
    GPIO_WritePin('A', 5, 0);
    GPIO_WritePin('A', 6, 0);
    GPIO_WritePin('A', 7, 0);
    GPIO_WritePin('A', 8, 0);
    GPIO_WritePin('A', 9, 0);
    GPIO_WritePin('A', 10, 0);

    // Set pin values depending on the number
    switch (number)
    {
    case 0:
        zero();
        break;
    case 1:
        one();
        break;
    case 2:
        two();
        break;
    case 3:
        three();
        break;
    case 4:
        four();
        break;
    case 5:
        five();
        break;
    case 6:
        six();
        break;
    case 7:
        seven();
        break;
    case 8:
        eight();
        break;
    case 9:
        nine();
        break;
    }
}

void zero()
{
    GPIO_WritePin('A', 4, 1);
    GPIO_WritePin('A', 5, 1);
    GPIO_WritePin('A', 6, 1);
    GPIO_WritePin('A', 7, 1);
    GPIO_WritePin('A', 8, 1);
    GPIO_WritePin('A', 9, 1);
}

void one()
{
    GPIO_WritePin('A', 5, 1);
    GPIO_WritePin('A', 6, 1);
}
void two()
{
    GPIO_WritePin('A', 4, 1);
    GPIO_WritePin('A', 5, 1);
    GPIO_WritePin('A', 7, 1);
    GPIO_WritePin('A', 8, 1);
    GPIO_WritePin('A', 10, 1);
}
void three()
{
    GPIO_WritePin('A', 4, 1);
    GPIO_WritePin('A', 5, 1);
    GPIO_WritePin('A', 6, 1);
    GPIO_WritePin('A', 7, 1);
    GPIO_WritePin('A', 10, 1);
}
void four()
{
    GPIO_WritePin('A', 5, 1);
    GPIO_WritePin('A', 6, 1);
    GPIO_WritePin('A', 9, 1);
    GPIO_WritePin('A', 10, 1);
}
void five()
{
    GPIO_WritePin('A', 4, 1);
    GPIO_WritePin('A', 6, 1);
    GPIO_WritePin('A', 7, 1);
    GPIO_WritePin('A', 9, 1);
    GPIO_WritePin('A', 10, 1);
}
void six()
{
    GPIO_WritePin('A', 4, 1);
    GPIO_WritePin('A', 6, 1);
    GPIO_WritePin('A', 7, 1);
    GPIO_WritePin('A', 8, 1);
    GPIO_WritePin('A', 9, 1);
    GPIO_WritePin('A', 10, 1);
}
void seven()
{
    GPIO_WritePin('A', 4, 1);
    GPIO_WritePin('A', 5, 1);
    GPIO_WritePin('A', 6, 1);
}
void eight()
{
    GPIO_WritePin('A', 4, 1);
    GPIO_WritePin('A', 5, 1);
    GPIO_WritePin('A', 6, 1);
    GPIO_WritePin('A', 7, 1);
    GPIO_WritePin('A', 8, 1);
    GPIO_WritePin('A', 9, 1);
    GPIO_WritePin('A', 10, 1);
}
void nine()
{
    GPIO_WritePin('A', 4, 1);
    GPIO_WritePin('A', 5, 1);
    GPIO_WritePin('A', 6, 1);
    GPIO_WritePin('A', 7, 1);
    GPIO_WritePin('A', 9, 1);
    GPIO_WritePin('A', 10, 1);
}
