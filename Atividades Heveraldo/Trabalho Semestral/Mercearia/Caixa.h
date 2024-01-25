#ifndef CAIXA_H_INCLUDED
#define CAIXA_H_INCLUDED

#include "Produtos.h"


void MostrarJanelaCaixa();      // aparencia da janela de caixa
void AtivarJanelaCaixa();       // funcoes ativas da caixa

void MostrarCompras(Produto C1);    // mostra as compras
void LimparCampos1();               // outra funcao de limpar parametros

void ListarCompras();           // cria a lista de produtos encontrados no carrinho
void Recibo();                  // cria a aparencia do recibo
void ListaRecibo();             // cria a lista "movel" de produtos no recibo

extern float Total;
extern QuantCompras;
extern Produto Carrinho[100];


#endif // CAIXA_H_INCLUDED
