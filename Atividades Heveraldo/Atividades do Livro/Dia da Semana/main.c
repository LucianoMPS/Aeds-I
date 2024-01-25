#include <stdio.h>
#include <stdlib.h>
double conversao(float dia, float mes, float ano)
{
    double Juliana;

    Juliana = (1461*(ano + 4800 +(mes - 14)))/4 + (367 *(mes - 2 - 12 *((mes - 14)/12)))/12 - (3 * ((ano + 4900 + (mes - 14)/12)/100))/4 + dia - 32075;

    return Juliana;
}


int main()
{
    float dia, mes, ano, DiaDaSemana;

    scanf("%f %f %f", &dia, &mes, &ano);

    DiaDaSemana = conversao(dia, mes, ano) / 7.0;

    if(DiaDaSemana == 0)
        printf("Segunda-Feira");

    if(DiaDaSemana == 1)
        printf("Terca-Feira");

    if(DiaDaSemana == 2)
        printf("Quarta-Feira");

    if(DiaDaSemana == 3)
        printf("Quinta-Feira");

    if(DiaDaSemana == 4)
        printf("Sexta-Feira");

    if(DiaDaSemana == 5)
        printf("Sabado");

    if(DiaDaSemana == 6)
        printf("Domingo");

    return 0;
}
