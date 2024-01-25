#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X;
    float Y;
    double total;

    scanf("%d", &X);
    scanf("%f", &Y);

    total = X / Y;

    printf("%.3f km/l", total);

    return 0;
}
