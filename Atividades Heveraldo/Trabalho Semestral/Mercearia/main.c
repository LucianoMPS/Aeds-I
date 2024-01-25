#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interface.h"
#include "Produtos.h"
#include "Tela Principal.h"
#include "Caixa.h"
#include "Vendas.h"


int main()
{
    // inicio tela login

    char Senha[51];
    char Correta[51] = "mercadinho do seu ze";
    Vendas Vnd1;

    char NomeCliente[35];
    int i;
    int r;


    textcoloreback(WHITE, RED);     // cria o menu de login
    Borda(40,10,40,10,1,0);

    gotoxy(42,11);
    printf("Para acessar o sistema digite a senha: ");

    Borda(42,15,36,1,0,0);          // fim menu de login


    while(1)
    {
        gotoxy(43,16);
        scanf(" %50[^\n]", &Senha);

        r = strcmp(Senha, Correta);


        if(r != 0)     // Se a senha digita for diferente da correta
        {
            gotoxy(43,16); printf("%*s", 36, " ");

            gotoxy(46,18);
            printf("Senha incorreta. Acesso negado!");

            if(getTecla() == TEC_ESC)
            {
                gotoxy(43,18); printf("%*s", 38, " ");
            }

            continue;
        }
        // fim tela login


        if(r == 0)  // se a senha for correta
        {

            TelaPrincipal();

            char Opcoes[][21] = {"  Cadastro", " Relatorio", "   Caixa","    Sair"};     // São as opcoes da tela principal
            char Compras[][21] = {"  Produtos", "  Carrinho" , "  Concluir" , "    Sair"};
            char Relatorios[][21] = {"  Estoque" , "   Vendas" , "    Sair"};
            int Opcao;

            while(1)
            {
                TelaPrincipal();
                Opcao = MenuBordaVertical(8,6, Opcoes, 4);


                if(Opcao == 0)      //Cadastro de produtos
                {
                    textcoloreback(BLACK, WHITE);
                    AtivarJanelaProdutos();
                    textcoloreback(WHITE, RED);
                }


                if(Opcao == 1)      // mostra os Relatorios
                {
                    while(1)
                    {
                        Borda(10, 8, 17, 13, 1, 0);
                        Opcao = MenuBordaVertical(12, 10, Relatorios, 3);


                        if(Opcao == 0)  // mostra o estoque
                        {
                            ListarProdutos();
                            continue;
                        }

                        if(Opcao == 1)  // mostra a caderneta de vendas
                        {
                            ListarVendas();
                            continue;
                        }

                        if(Opcao == 2)
                            break;
                    }

                    continue;
                }


                if(Opcao == 2)     // tela de compras
                {
                    while(1)
                    {
                        Borda(10, 8, 17, 17, 1, 0);
                        Opcao = MenuBordaVertical(12, 10, Compras, 4);

                        if(Opcao == 0)  // add produtos ao carrinho
                        {
                        textcoloreback(BLACK, WHITE);
                        AtivarJanelaCaixa();
                        textcoloreback(WHITE, RED);
                        }

                        if(Opcao == 1)  // mostra o carrinho
                        {
                            ListarCompras();
                        }

                        if(Opcao == 2)  // finaliza a compra
                        {
                                AbrirArquivoVendas();

                                Borda(32,8,42,5,1,0);   // nome do cliente

                                gotoxy(47,9);
                                printf("Digite seu Nome");

                                Borda(33,10,40,1,0,0);

                                gotoxy(34,11);
                                scanf(" %34[^\n]", NomeCliente);  // fim nome do cliente


                                Recibo();

                                ListaRecibo();


                                strcpy(Vnd1.NomeCliente2, NomeCliente);  // inicio armazena caderneta

                                for(i=0;i<QuantCompras;i++)
                                {
                                    Vnd1.QuantidadeComprasCliente += Carrinho[i].Quantidade;
                                }

                                Vnd1.TotalGasto = Total;

                                InserirVenda(Vnd1); // fim armazena caderneta


                                Total = 0;          // zera o carrinho
                                QuantCompras = 0;

                                fclose(fpVendas);
                        }

                        if(Opcao == 3)
                            break;
                    }

                    continue;
                }

                if(Opcao == 3)   // fecha o programa
                {
                    gotoxy(0,26);
                    return;
                }

             }

         }
         break;
    }
    return 0;
}
