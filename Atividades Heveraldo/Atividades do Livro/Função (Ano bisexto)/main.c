#include <stdio.h>
#include <stdlib.h>

int bisexto(int ano)
{
    if((ano/100 != 0 && ano%4 == 0) || ano%400 ==0)
        return 1;
    else
        return 0;
}

int main()
{
    int x, resultado;

    scanf("%d", &x);
    resultado = bisexto(x);


    if(resultado == 1)
      printf("é bisexto");

    else
      printf("não é bisexto");

    return 0;
}
