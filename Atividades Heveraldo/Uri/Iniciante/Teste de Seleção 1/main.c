#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, C, D;
    int SomaCD, SomaAB, Par;

    scanf("%d %d %d %d", &A, &B, &C, &D);

    SomaCD = C + D;
    SomaAB = A + B;
    Par = A % 2;

    if((B>C) && (D>A) && (SomaCD > SomaAB) && (C>0) && (D>0) && (Par == 0))
        printf("Valores aceitos\n");
    else
        printf("Valores nao aceitos\n");

    return 0;
}
