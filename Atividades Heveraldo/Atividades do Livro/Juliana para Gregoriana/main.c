#include <stdio.h>
#include <stdlib.h>

long int Dia, Mes, Ano;

long int Gregoriano(double Juliana)
{
    long int B, N, K, J;

    B = Juliana + 68569;
    N = (4 * B)/ 146097;
    B = B - ((146097 * N + 3)/4);
    K = 4000 * (B + 1)/ 1461001; /* TALVEZ ESTEJA ERRADO */
    B = B - (1461 * K)/ 4 + 31;
    J = (80 * B)/2447;

    Dia = B - (2447 * J)/80;
    B = (J/11);

    Mes = J + 2 - (12*B);

    Ano = 100 * (N - 49) + K + B;
}

int main()
{
    double Juliana;

    printf("digite a data Juliana: \n");
    scanf("%d", &Juliana);

    Gregoriano(Juliana);

    printf("%ld%ld%ld", Dia, Mes, Ano);

    return 0;
}
