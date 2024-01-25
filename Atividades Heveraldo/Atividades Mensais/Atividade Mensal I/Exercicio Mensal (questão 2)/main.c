#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont, sinal;
    cont = 0;
    sinal = 1;

    double S, A, B, AB;
    S = 0;
    A = 3;
    B = 1;

    while(cont < 15)
    {
        AB = A/B;
        S = S + AB * sinal;

        sinal = sinal * (-1);
        A += 3;
        B *= 7;

    cont = cont + 1;
    }

    printf("S = %f", S);
    return 0;
}
