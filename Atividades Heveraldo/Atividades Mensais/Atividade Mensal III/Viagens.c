#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Viagens.h"

FILE *fpViagens;
FILE *fpViagens2;

Viagem AddViagem()
{
    Viagem X1;

    printf("Qual o destino da viagem? ");
    scanf(" %[^\n]", X1.Destino);

    printf("Digite a data no modelo dd/mm/aa: ");
    scanf("%s", X1.Data);

    printf("Digite a quantidade de dias: ");
    scanf("%d", &X1.Dias);

    printf("Digite o valor da viagem: ");
    scanf("%f", &X1.Valor);

    return X1;
}

void MostrarViagem(Viagem X2)
{
    printf("\n%s \n", X2.Destino);
    printf("%s \n", X2.Data);
    printf("%d \n", X2.Dias);
    printf("R$ %.2f \n", X2.Valor);
}

void InserirViagem(Viagem X3)
{
    fpViagens = fopen("Viagens.txt", "ab");

    if(fpViagens == NULL)
    {
        printf("erro\n");
        return;
    }

    fseek(fpViagens,0,SEEK_END);

    fwrite(&X3, sizeof(Viagem), 1,fpViagens);

    fclose(fpViagens);
}

Viagem PesquisarViagem(char destino[21])
{
    Viagem X5;

    fpViagens = fopen("Viagens.txt", "rb");

    fseek(fpViagens,0,SEEK_SET);

    while(fread(&X5,sizeof(Viagem),1,fpViagens))
    {
        if(strcmp(X5.Destino,destino)==0)
        {
            fclose(fpViagens);
            return X5;
        }

    }

    strcpy(X5.Destino, "Nulo");
    return X5;

    fclose(fpViagens);
}


void BinParaTxt()
{
    Viagem X6;
    int TotalViagens = 0;
    float ValorTotal = 0.0;

    fpViagens = fopen("Viagens.txt", "rb");
    fpViagens2 = fopen("Relatorios.txt", "w");

    fprintf(fpViagens2, "Relatorio de Viagens\n\n");

    fprintf(fpViagens2, "%-21s %-16s %-17s %s\n", "Destino", "Data", "Duração", "Valor");

    while(fread(&X6, sizeof(Viagem), 1,fpViagens))
    {
        fprintf(fpViagens2, "%-22s %-16s %-17d %.2f\n", X6.Destino, X6.Data, X6.Dias, X6.Valor);

        TotalViagens++;
        ValorTotal += X6.Valor;
    }

    fprintf(fpViagens2,"\n%d Viagens                     Custo Total: R$%.2f", TotalViagens, ValorTotal);

    fclose(fpViagens);
    fclose(fpViagens2);

}


