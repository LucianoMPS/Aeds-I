#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados
{
    char Nome[51];
    char Endereco[61];
    float Preco;
    char Comida[21];
};

struct dados leitura()
{
      struct dados pedido;

      printf("Digite seu nome: ");
      scanf(" %51[^\n]", &pedido.Nome);

      printf("Digite seu endereco: ");
      scanf(" %61[^\n]", &pedido.Endereco);

      printf("Digite o preco medio: ");
      scanf("%f", &pedido.Preco);

      printf("Digite o tipo de comida: ");
      scanf(" %20[^\n]", &pedido.Comida);

      return pedido;
}

struct dados impressao(struct dados pedido)
{
    printf("\nNome: %s\n", pedido.Nome);

    printf("Endereco: %s\n", pedido.Endereco);

    printf("Total: R$%.2f\n", pedido.Preco);

    printf("O tipo de comida foi: %s\n", pedido.Comida);
}


int main()
{
    struct dados pedido1;

    pedido1 = leitura();

    impressao(pedido1);


    return 0;
}
