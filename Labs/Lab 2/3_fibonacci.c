#include <stdio.h>
#include <stdlib.h>

#define sc(x) scanf("%d", &x)

int main()
{
    while (1)
    {
        int terms;
        unsigned long long first = 0, second = 1, third;
        printf("Enter the number of terms:\n");
        sc(terms);
        if (terms == 0)
            printf("");
        if (terms == 1)
            printf("%d", first);
        if (terms >= 2)
        {
            printf("%d %d ", first, second);
            terms -= 2;
            while (terms--)
            {
                third = first + second;
                printf("%llu ", third);
                first = second;
                second = third;
            }
        }
        printf("\n");
    }
    return 0;
}
