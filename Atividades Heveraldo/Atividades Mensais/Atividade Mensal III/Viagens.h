#ifndef VIAGENS_H_INCLUDED
#define VIAGENS_H_INCLUDED

struct viagem
{
    char Destino[101];
    char Data[11];
    int Dias;
    float Valor;
};
typedef struct viagem Viagem;

Viagem AddViagem();
void MostrarViagem(Viagem X2);
void InserirViagem(Viagem X3);
Viagem PesquisarViagem(char destino[21]);
void BinParaTxt();


#endif // VIAGENS_H_INCLUDED
