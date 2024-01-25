#include <stdio.h>
#include <stdlib.h>

int main()
{

    int Ano, Mes, Dia, DiasTotal;

    scanf("%d", &DiasTotal);

    Ano = DiasTotal/365;
        DiasTotal = DiasTotal%365;

    Mes = DiasTotal/30;
        DiasTotal = (DiasTotal%365)%30;


    Dia = DiasTotal%30;

    printf("%d ano (s)\n", Ano);
    printf("%d mes (es)\n", Mes);
    printf("%d dia (s)\n", Dia);

    return 0;
}
