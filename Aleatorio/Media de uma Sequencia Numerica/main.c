#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, PrimeiroNumero, Quant, Variacao;
    float Media, Soma;

    printf("Qual o tamanho da sequencia numerica? ");
    scanf("%d", &Quant);

    printf("\nQual o primeiro termo da sequencia? ");
    scanf("%d", &PrimeiroNumero);

    printf("\nQual a variacao dos valores? ");
    scanf("%d", &Variacao);

    Soma = PrimeiroNumero;

    for(i = 0; i < Quant; i++)
        Soma += Variacao;

    Media = Soma / Quant;

    printf("\nA media e: %.2f\n", Media);

    return 0;
}
