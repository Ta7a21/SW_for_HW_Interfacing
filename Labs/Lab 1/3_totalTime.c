#include <stdio.h>
#include <stdlib.h>

#define sc(x) scanf("%d", &x)

int main()
{
    int time;
    while (1)
    {
        printf("Enter total time elapsed in seconds: ");
        sc(time);
        int hours = time / (60 * 60);
        time %= (60 * 60);
        int minutes = time / 60;
        time %= 60;
        printf("%d:%d:%d\n", hours, minutes, time);
    }
    return 0;
}
