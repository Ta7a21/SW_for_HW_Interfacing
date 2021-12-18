#include <stdio.h>
#include <stdlib.h>

#define sc(x) scanf("%d", &x)

int main()
{
    int u, a, t;
    while (1)
    {
        printf("Enter the initial velocity: ");
        sc(u);
        printf("Enter the acceleration: ");
        sc(a);
        printf("Enter the elapsed time: ");
        sc(t);
        printf("The final velocity equals: %d\n", u + a * t);
        printf("The distance traversed equals: %lf\n", u * t + 0.5 * a * t * t);
    }
    return 0;
}
