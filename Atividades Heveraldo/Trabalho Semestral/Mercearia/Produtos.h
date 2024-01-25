#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED

struct produto
{
    int Codigo;
    char Nome[14];
    float Preco;
    int Quantidade;     // lembrar de n passar de 999
};
typedef struct produto Produto;


Produto DigitarProduto();           // faz o cadastro de produtos
void MostrarProdutos(Produto Prod); // mostra os produtos
void LimparCampos();                // limpa os campos de preencher

int PesquisarProduto(int Codigo);   // pesquisa um produto pelo cod


void MostrarJanelaProdutos();       // aparencia da janela de produto
void AtivarJanelaProdutos();        // funcoes ativas da janela

void ListarProdutos();              // mostra a lista do estoque


void AbrirArquivoProdutos();        // cria, le e altera o arquivo
void InserirProduto(Produto Prod);  // insere dados no arquivo
int PesquisarProduto(int Cod);      // pesquisa dados no arquivo
Produto LerProduto(int Posicao);    // imprime os dados requeridos do arquivo
void ReescreverProduto(Produto Prod, int Posicao);    // altera dados na determinada posicao do arquivo

FILE *fpProdutos;


#endif // PRODUTOS_H_INCLUDED
