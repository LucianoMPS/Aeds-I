#include <stdio.h>
#include <stdlib.h>

struct empregados
{
    int numero;
    char nome[51];
    char cargo[51];
    float salario;
};

typedef struct empregados Empregados;

Empregados ArmazenaDados()
{
    Empregados dados;

    printf("\nDigite seu numero: \n");
    scanf("%d", &dados.numero);

    printf("Digite seu Nome: \n");
    scanf(" %[^\n]", &dados.nome);

    printf("Digite seu Cargo: \n");
    scanf(" %[^\n]", &dados.cargo);

    printf("Digite seu Salario: \n");
    scanf("%f", &dados.salario);


    return dados;
}

float CalculoINSS(Empregados calculo)
{
    float INSS;

    if(calculo.salario <= 1800.00)
        INSS = (calculo.salario * 8)/100;

    else if(calculo.salario <= 3500.00)
        INSS = (calculo.salario * 10)/100;

    else if(calculo.salario > 3500.00)
        INSS = (calculo.salario * 11)/100;

    return INSS;
}

int main()
{
     int i;
     Empregados contratados[5];
     float INSS=0.0;

     for(i=0;i<5;i++)
        contratados[i] = ArmazenaDados();

     for(i=0;i<5;i++)
        INSS += CalculoINSS(contratados[i]);

     printf("\n%.2f", INSS);

    return 0;
}
