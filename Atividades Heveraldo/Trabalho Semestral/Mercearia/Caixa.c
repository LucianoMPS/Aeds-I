#include <stdio.h>

#include "Caixa.h"
#include "Interface.h"
#include "Produtos.h"

#define PX 30
#define PY 2

Produto Carrinho[100]; // vetor que guarda os produtos comprados
QuantCompras = 0;
float Total = 0;
int VariacaoEstoque;


void MostrarJanelaCaixa()
{
    Borda(PX, PY, 69, 19, 1 , 0);

    gotoxy(PX + 22,PY + 1); printf("Caixa");

    gotoxy(PX + 5,PY +  4); printf("    Codigo: ");
    gotoxy(PX + 5,PY +  7); printf("      Nome: ");
    gotoxy(PX + 5,PY + 10); printf("     Preco: ");
    gotoxy(PX + 5,PY + 13); printf("Quantidade: ");

    Borda(PX + 16,PY + 3, 20, 1, 0, 0);  // Borda das especificações
    Borda(PX + 16,PY + 6, 20, 1, 0, 0);
    Borda(PX + 16,PY + 9, 20, 1, 0, 0);
    Borda(PX + 16,PY + 12, 20, 1, 0, 0);
}


void MostrarCompras(Produto C1)
{
    gotoxy(PX + 17,PY + 4); printf("%d\n", C1.Codigo);
    gotoxy(PX + 17,PY + 7); printf("%s\n", C1.Nome);
    gotoxy(PX + 17,PY + 10); printf("%.2f\n", C1.Preco);
    gotoxy(PX + 17,PY + 13); printf("%d\n", C1.Quantidade);
}


void LimparCampos1()
{
    gotoxy(PX + 16,PY + 4);printf("%*s", 10, " ");
    gotoxy(PX + 16,PY + 7);printf("%*s", 50, " ");
    gotoxy(PX + 16,PY + 10);printf("%*s", 20, " ");
    gotoxy(PX + 16,PY + 13);printf("%*s", 12, " ");
}


void AtivarJanelaCaixa()
{
    char Opcoes[][21] = {"    Add", " Descartar", "  Cancelar", "  Voltar"};     // definicao dos botoes
    int Opcao, Codigo, Posicao, PosicaoR, i;

    Produto C1, ProdLeitura, ProdVariaEstoque, ProdVariaEstoque2;

    AbrirArquivoProdutos();

    do{
        MostrarJanelaCaixa();

        gotoxy(PX + 17,PY + 4); scanf("%d", &Codigo);
        Posicao = PesquisarProduto(Codigo);

        if(Posicao == -1)   // ou seja, nenhum produto com esse cod encontrado
        {
            gotoxy(PX + 40,PY + 4);
            printf("Produto nao encontrado!");
            gotoxy(PX + 17, PY + 4);
            if(getTecla() ==  TEC_ESC) continue;
        }


        else{                           // produto encontrado
            C1 = LerProduto(Posicao);
            MostrarCompras(C1);
            gotoxy(PX + 17,PY + 13);printf("%*s", 12, " ");
        }


        while(1)
        {
            tipocursor(0);
            Opcao = MenuBorda(PX + 4,PY + 16, Opcoes, 4);

            if(Opcao == 0) // add produto ao carrinho
            {
                gotoxy(PX + 40,PY + 13);
                printf("Digite a quantidade!");

                gotoxy(PX + 17,PY + 13);        // pede a quantidade do produto
                scanf("%d", &C1.Quantidade);


                fseek(fpProdutos, Posicao, SEEK_SET);   // cria uma copia do struct  com os dados de produto
                fread(&ProdVariaEstoque, sizeof(Produto), 1, fpProdutos);


                if(C1.Quantidade > ProdVariaEstoque.Quantidade)    // se quantidade exceder o estoque
                {
                    gotoxy(PX + 40, PY + 13);
                    printf("Quantidade acima do estoque");

                    gotoxy(PX + 40, PY + 14);
                    printf("Estoque atual: %d", ProdVariaEstoque.Quantidade);

                    if(getTecla() == TEC_ESC)
                        break;
                }


                Carrinho[QuantCompras] = C1;        // armazena os dados de produtos coletados no carrinho

                Total += Carrinho[QuantCompras].Preco * Carrinho[QuantCompras].Quantidade;  // é o valot total da compra


                VariacaoEstoque = C1.Quantidade;
                ProdVariaEstoque.Quantidade -= VariacaoEstoque;

                ReescreverProduto(ProdVariaEstoque, Posicao);

                fflush(fpProdutos);

                QuantCompras++;

                break;
            }


           if(Opcao == 1)   // alterar compra
           {
                break;
           }


           if(Opcao == 2)  // cancelar compra
           {
                for(i = 0; i < QuantCompras; i++)
                {
                    PosicaoR = PesquisarProduto(Carrinho[i].Codigo);

                    ProdVariaEstoque2 = LerProduto(PosicaoR);

                    ProdVariaEstoque2.Quantidade += Carrinho[i].Quantidade;

                    ReescreverProduto(ProdVariaEstoque2, PosicaoR);
                }

                fflush(fpProdutos);

                Total = 0;
                QuantCompras = 0;

                return;
           }


           if(Opcao == 3)   // sair da janela de compras
              return;

        }

     } while(Opcao != 3);

     tipocursor(1);

     fclose(fpProdutos);
}


void ListarCompras()
{
    int i;
    char Linhas[QuantCompras+1][101];


    sprintf(Linhas[0], "%-5s %-50s %-9s %-8s", "Cod.", "Nome", "Preco", "Quant");


    for(i=0;i < QuantCompras;i++){
            sprintf(Linhas[i+1], "%-5d %-50s R$%-8.2f %-8d", Carrinho[i].Codigo, Carrinho[i].Nome,
                                                   Carrinho[i].Preco, Carrinho[i].Quantidade);
    }

    Listagem(PX + 0, PY + 0, 79, 5, Linhas, QuantCompras);
}

void Recibo()
{
    textcoloreback(BLACK, WHITE);   // recibo

    Borda(50,0,30,26,0,0);
    gotoxy(59,1);
    printf("MERCEARIA O&M");
    gotoxy(51,2);
    printf("==============================");
    gotoxy(52,3);
    printf("Mercearia Oliveira e Morais");
    gotoxy(51,4);
    printf("CNPJ: XX. XXX. XXX/0001-XX");
    gotoxy(51,5);
    printf("Rua Seu Ze, 101 - Bairro Falso");
    gotoxy(51,6);
    printf("------------------------------");

    gotoxy(51,24);
    printf("TOTAL:           R$%1.2f", Total);
    gotoxy(51,25);
    printf("==============================");
    gotoxy(60,26);
    printf("VOLTE SEMPRE");
}

void ListaRecibo()
{
    int i;
    char Linhas[QuantCompras+1][101];


    sprintf(Linhas[0], "%-14s %-7s %-1s", "Nome", "Preco", "Quant");


    for(i=0;i < QuantCompras;i++){
            sprintf(Linhas[i+1], "%-14s R$%-7.2f %-1d", Carrinho[i].Nome,
                                                   Carrinho[i].Preco, Carrinho[i].Quantidade);
    }

    Listagem(PX + 21, PY + 5, 28, 14, Linhas, QuantCompras);
}
