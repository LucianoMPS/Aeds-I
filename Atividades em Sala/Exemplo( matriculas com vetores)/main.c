#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Matriculas
Nomes
Notas


   |A|l|i|c|e| | | |
   |B|e|a|t|r|i|z| |
   |C|a|r|l|o|s| | |
   |M|a|r|c|e|l|o| |
   |P|a|u|l|o| | | |
   |T|i|a|g|o| | | |
*/
#define MAX_ALUNOS 20


int main()
{
    int i, Quant = 0;
    int Matriculas[MAX_ALUNOS];
    char Nomes[MAX_ALUNOS][51];
    double Notas[MAX_ALUNOS];


    for(i = 0; i < MAX_ALUNOS; i++)
        {
        printf("Digite a Matricula (zero para finalizar): ");
        scanf("%d", &Matriculas[i]);
        if(Matriculas[i] == 0) break;

        printf("Digete o Nome: ");
        scanf(" %50[^\n]", Nomes[i]);

        printf("Digite a Nota: ");
        scanf("%lf", &Notas[i]);

        Quant++;
        }


    printf("\n\n");


    printf("Matricula Nome                                               Nota\n");
    for(i = 0; i < Quant; i++)
    {
        printf("%09d %-50s %10.1lf\n", Matriculas[i], Nomes[i], Notas[i]);
    }

    printf("\n%d Alunos Matriculados!\n", Quant);
    return 0;
}
