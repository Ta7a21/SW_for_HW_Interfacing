#include <stdio.h>
#include <stdlib.h>

#define sc(x) scanf("%d", &x)

double power(int base, int power)
{
    double result = 1;
    while (power--)
        result *= base;
    return result;
}

double factorial(int base)
{
    double result = 1;
    for (int i = 2; i <= base; i++)
        result *= i;
    return result;
}

int main()
{
    while (1)
    {
        int exponent, iterations;
        double result = 0;
        puts("Enter the exponent:");
        sc(exponent);
        puts("Enter the number of iterations:");
        sc(iterations);
        for (int i = 0; i < iterations; i++)
        {
            result += (power(exponent, i)) / (factorial(i));
        }
        printf("Result: %lf\n", result);
    }
    return 0;
}
