#include <stdio.h>
#include <stdlib.h>

#define sc(x) scanf("%d", &x)

int smallest(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

int largest(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int main()
{
    int num1, num2, num3;
    while (1)
    {
        printf("Enter three different integers: ");
        sc(num1), sc(num2), sc(num3);
        printf("Sum is: %d\n", num1 + num2 + num3);
        printf("Average is: %lf\n", (num1 + num2 + num3) / 3.0);
        printf("Product is: %d\n", num1 * num2 * num3);
        printf("Smallest is: %d\n", smallest(smallest(num1, num2), num3));
        printf("Largest is: %d\n", largest(largest(num1, num2), num3));
    }
    return 0;
}
