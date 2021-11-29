#include <stdio.h>
#include <stdlib.h>

#define sc(x) scanf("%d", &x)
#define scc(x) scanf(" %c", &x)

int main()
{
    while (1)
    {
        unsigned char number, output;
        int rotateCycles;
        char rotateOption;
        printf("Enter the 8bit number:\n");
        sc(number);
        printf("Enter the number of rotate cycles:\n");
        sc(rotateCycles);
        printf("Enter the rotate option (l/r):\n");
        scc(rotateOption);
        switch (rotateOption)
        {
        case 'l':
            output = (number << rotateCycles) | (number >> 8 - rotateCycles);
            break;
        case 'r':
            output = (number >> rotateCycles) | (number << 8 - rotateCycles);
            break;
        }
        printf("%d\n", output);
    }
    return 0;
}
