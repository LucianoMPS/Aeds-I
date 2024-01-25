#include <stdio.h>
#include <stdlib.h>

int main()
{
    int DDD, min, minT, ligacoes;
    ligacoes = 0;
    minT = 0;
    DDD = 1;

    double valor;
    valor = 0;

    while(1)
    {
       printf("Digite o DDD: ");
       scanf("%d", &DDD);

       if(DDD == 0) break;

       printf("Digite o tempo da ligacao ");
       scanf("%d", &min);
       minT = minT + min;

       if(DDD == 38 && DDD != 0)
        valor += 0.30 * minT;

       else if(DDD != 38 && DDD != 0)
        valor += 0.50 * minT;

       ligacoes += 1;

    }

    printf("\nquantidade de chamadas: %d\n", ligacoes);
    printf("quantidade de minutos: %d\n", minT);
    printf("valor a ser pago R$%.2f\n", valor);

    return 0;
}
