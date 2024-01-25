#include <stdio.h>
#include <stdlib.h>

double conversao(int dia, int mes, int ano)
{
    double Juliana;

    Juliana = (1461*(ano + 4800 +(mes - 14)))/4 + (367 *(mes - 2 - 12 *((mes - 14)/12)))/12 - (3 * ((ano + 4900 + (mes - 14)/12)/100))/4 + dia - 32075;

    return Juliana;
}

int main()
{
    int ano, mes, dia;
    double DataJuliana;

    printf("Digite uma Data gregoriana: dia/mes/ano\n");
    scanf("%d %d %d", &ano, &mes, &dia);

    DataJuliana = conversao(dia, mes, ano);

    printf("A data e: %.6lf", DataJuliana);

    return 0;
}
