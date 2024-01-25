#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "Viagens.h"

int main()
{
    int Opcao;
    Viagem Teste, Posicao;
    char DestinoProcurado[21];


    do{
        printf("\nQual funcao voce deseja utilizar? \n");
        printf("0-Sair, 1-cadastrar, 2-pesquisar, 3-relatorio \n");

        scanf("%d", &Opcao);

        if(Opcao == 1)
        {
            Teste = AddViagem();
            InserirViagem(Teste);
            continue;
        }

        if(Opcao == 2)
        {
            printf("\nQual o destino a ser procurado? ");
            scanf("%20s", DestinoProcurado);

            Posicao = PesquisarViagem(DestinoProcurado);

            if(strcmp(Posicao.Destino,"Nulo")==0)
            {
                printf("Destino não encontrado \n");
                continue;
            }

            MostrarViagem(Posicao);
            continue;
        }


        if(Opcao == 3)
        {
            BinParaTxt();
            continue;
        }


        if(Opcao == 0)
            break;

    } while(Opcao != 0);

    return 0;
}
