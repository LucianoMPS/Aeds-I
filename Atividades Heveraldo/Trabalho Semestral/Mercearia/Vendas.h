#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED

struct vendas
{
    char NomeCliente2[35];
    int QuantidadeComprasCliente;
    float TotalGasto;
};
typedef struct vendas Vendas;

void ListarVendas();    // lista as vendas feitas em uma tabelinha


void AbrirArquivoVendas();  // abre o arquivo de vendas
void InserirVenda(Vendas compra);   // add compras ao relatorio

FILE *fpVendas;


#endif // VENDAS_H_INCLUDED
