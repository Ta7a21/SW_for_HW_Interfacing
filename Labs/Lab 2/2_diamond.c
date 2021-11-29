#include <stdio.h>
#include <stdlib.h>

int main()
{
    int spaces = 4, astrisk = 1, iterations = 0, reverse = 0;
    while (iterations != -1)
    {
        for (int i = 0; i < spaces; i++)
            printf(" ");
        for (int i = 0; i < astrisk; i++)
            printf("*");
        for (int i = 0; i < spaces; i++)
            printf(" ");
        if (iterations == 4)
            reverse = 1;
        if (reverse)
        {
            astrisk -= 2;
            spaces++;
            iterations--;
        }
        else
        {
            astrisk += 2;
            spaces--;
            iterations++;
        }
        printf("\n");
    }
    return 0;
}
