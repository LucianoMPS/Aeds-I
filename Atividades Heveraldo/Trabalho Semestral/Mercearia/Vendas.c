#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Vendas.h"
#include "Interface.h"

#define PX 30
#define PY 2


void AbrirArquivoVendas()
{
    fpVendas = fopen("Vendas.txt", "rb+");

	if(fpVendas == NULL)
    {
		fpVendas = fopen("Vendas.txt", "wb+");

		if(fpVendas == NULL){
			printf("Não abriu Vendas.txt!\n");
			exit(1);
        }
    }
}


void InserirVenda(Vendas compra)
{
    fseek(fpVendas, 0, SEEK_END);
    fwrite(&compra, sizeof(Vendas), 1, fpVendas);
}


void ListarVendas()
{
    int QuantVendas = 0;
    char Linhas[1000][101];
    Vendas WishList;

    AbrirArquivoVendas();

    sprintf(Linhas[0], "%-31s %-20s %-1s", "Nome", "Quantidade", "Total");

    fseek(fpVendas, 0, SEEK_SET);
    while(fread(&WishList, sizeof(Vendas), 1, fpVendas))
    {
        sprintf(Linhas[QuantVendas+1], "%-35s %-13d R$%.2f", WishList.NomeCliente2, WishList.QuantidadeComprasCliente, WishList.TotalGasto);
        QuantVendas++;
    }

    Listagem(PX + 0, PY + 0, 60, 15, Linhas, QuantVendas);

    fclose(fpVendas);
}
