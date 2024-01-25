#include <stdio.h>
#include <stdlib.h>

int main()
{
    double M[12] [12];
    int i, j;
    int min=1, max=10;

    double soma = 0.0;

    char operacao;
    double num;

    scanf("%c", &operacao);

    for(i=0;i<12;i++)
        for(j=0;j<12;j++)
        {
             scanf("%lf", &num);
             M[i] [j] = num;
        }

     for(i=0;i<5;i++)
        for(j=i+1;j <= 10-i;j++)
           soma += M[i] [j];


     if(operacao == 'M')
        printf("%.1lf\n", (soma/30.0));

     if(operacao == 'S')
        printf("%.1lf\n", soma);

    return 0;
}
