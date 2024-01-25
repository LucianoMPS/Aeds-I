#include <stdio.h>

#include "Produtos.h"
#include "Interface.h"

#define PX 30
#define PY 2


void AbrirArquivoProdutos()
{
    fpProdutos = fopen("Produtos.txt", "rb+");

	if(fpProdutos == NULL)
    {
		fpProdutos = fopen("Produtos.txt", "wb+");

		if(fpProdutos == NULL){
			printf("Não abriu Produtos.txt!\n");
			exit(1);
        }
    }
}


void InserirProduto(Produto Prod)
{
    fseek(fpProdutos, 0, SEEK_END);
    fwrite(&Prod, sizeof(Produto), 1, fpProdutos);
}


int PesquisarProduto(int Cod)
{
    Produto Prod;

    fseek(fpProdutos, 0, SEEK_SET);

    while(fread(&Prod, sizeof(Produto), 1, fpProdutos))
    {
        if(Prod.Codigo == Cod)
        {
            return ftell(fpProdutos) - sizeof(Produto);
        }
    }
    return -1;
}


Produto LerProduto(int Posicao)
{
    Produto Prod;

    fseek(fpProdutos, Posicao, SEEK_SET);
    fread(&Prod, sizeof(Produto), 1, fpProdutos);

    return Prod;
}


void ReescreverProduto(Produto Prod, int Posicao)
{
    fseek(fpProdutos, Posicao, SEEK_SET);
    fwrite(&Prod, sizeof(Produto), 1, fpProdutos);
}


void MostrarJanelaProdutos()
{
    Borda(PX, PY, 69, 20, 1 , 0);

    gotoxy(PX + 20,PY + 1); printf("CADASTRO DE PRODUTOS");

    gotoxy(PX + 5,PY +  4); printf("    Codigo: ");
    gotoxy(PX + 5,PY +  7); printf("      Nome: ");
    gotoxy(PX + 5,PY + 10); printf("     Preco: ");
    gotoxy(PX + 5,PY + 13); printf("Quantidade: ");

    Borda(PX + 16,PY + 3, 20, 1, 0, 0);  /* Borda das especificações*/
    Borda(PX + 16,PY + 6, 20, 1, 0, 0);
    Borda(PX + 16,PY + 9, 20, 1, 0, 0);
    Borda(PX + 16,PY + 12, 20, 1, 0, 0);
}


Produto DigitarProduto()
{
    Produto Prod;

    gotoxy(PX + 17,PY + 7); scanf(" %13[^\n]", &Prod.Nome);
    fflush(stdin);
    gotoxy(PX + 17,PY + 10); scanf("%f", &Prod.Preco);
    gotoxy(PX + 17,PY + 13); scanf("%d", &Prod.Quantidade);

    return Prod;
}


void MostrarProdutos(Produto Prod)
{
    gotoxy(PX + 17,PY + 4); printf("%d\n", Prod.Codigo);
    gotoxy(PX + 17,PY + 7); printf("%s\n", Prod.Nome);
    gotoxy(PX + 17,PY + 10); printf("%.2f\n", Prod.Preco);
    gotoxy(PX + 17,PY + 13); printf("%d\n", Prod.Quantidade);
}


void LimparCampos()
{
    gotoxy(PX + 17,PY + 4); printf("%*s", 20, " ");
    gotoxy(PX + 17,PY + 7); printf("%*s", 20, " ");
    gotoxy(PX + 17,PY + 10); printf("%*s", 20, " ");
    gotoxy(PX + 17,PY + 13); printf("%*s", 20, " ");
}


void AtivarJanelaProdutos()
{
    char Opcoes[][21] = {"  Salvar", "  Alterar", "  Cancelar", "    Sair"};    // sao as opcoes dos butoes
    int Opcao, Codigo, Posicao;
    Produto X;

    AbrirArquivoProdutos();

    do{
        MostrarJanelaProdutos();

        gotoxy(PX + 17, PY + 4); scanf("%d", &Codigo);
        Posicao = PesquisarProduto(Codigo);

        if(Posicao == -1)   // ou seja, cod nao encontrado
        {
            X = DigitarProduto();
            X.Codigo = Codigo;
        }

        else{               // codigo encontrado
            X = LerProduto(Posicao);
            MostrarProdutos(X);
        }


        while(1)
        {
            tipocursor (0);
            Opcao = MenuBorda(PX + 7,PY + 16, Opcoes, 4);

            if(Opcao == 0)  // opacao salvar
            {
                if(Posicao == -1)               // se nao houver um produto com esse cod
                {
                   InserirProduto(X);
                }

                else{                           // se tiver um produto com esse cod
                   ReescreverProduto(X, Posicao);
                }
                break;
            }


            if(Opcao == 1)  // opcao alterar
            {
                tipocursor(1);

                LimparCampos();
                gotoxy(PX + 17,PY + 4); printf("%d", X.Codigo);

                X = DigitarProduto();
                X.Codigo = Codigo;

                tipocursor(0);
            }


            if(Opcao == 2)  // opcao cancelar
                break;


            if(Opcao == 3)  // opcao sair
                break;      // antes era um rerturn
        }


     } while(Opcao != 3);

     tipocursor(1);

     fclose(fpProdutos);
}


void ListarProdutos()
{
    int QuantProdutos1 = 0;
    char Linhas[1000][101];
    Produto ProdList;

    AbrirArquivoProdutos();

    sprintf(Linhas[0], "%-5s %-50s %-9s %-8s", "Cod.", "Nome", "Preco", "Quant");


    fseek(fpProdutos, 0, SEEK_SET);
    while(fread(&ProdList, sizeof(Produto), 1, fpProdutos))
    {
        sprintf(Linhas[QuantProdutos1+1], "%-5d %-50s R$%-8.2f %-8d", ProdList.Codigo, ProdList.Nome,
                                                   ProdList.Preco, ProdList.Quantidade);

        QuantProdutos1++;
    }

    Listagem(PX + 0, PY + 0, 77, 20, Linhas, QuantProdutos1);

    fclose(fpProdutos);
}
