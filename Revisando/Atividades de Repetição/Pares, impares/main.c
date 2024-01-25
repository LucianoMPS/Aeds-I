#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    int pares, impares, positivo, negativo;
    pares = impares = positivo = negativo = 0;

    for(i=0;i<5;i++)
    {
        scanf("%d", &n);

       if(n%2 == 0)
        pares += 1;
       else
        impares += 1;

       if(n > 0 )
        positivo += 1;
       if(n < 0 && n != 0)
        negativo += 1;

    }

    printf("%d valor(es) par(es)\n", pares);
    printf("%d valor(es) impar(es)\n", impares);
    printf("%d valor(es) positivo(s)\n", positivo);
    printf("%d valor(es) negativo(s)\n", negativo);

    return 0;
}
