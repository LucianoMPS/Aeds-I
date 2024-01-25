#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, fatorial;
    fatorial = 1;

    scanf("%d", &n);

    for(i=n;i >= 1;i -= 1)
        fatorial = fatorial * i;

    printf("%d\n", fatorial);

    return 0;
}
