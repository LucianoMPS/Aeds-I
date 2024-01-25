#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <windows.h>

#define TEC_ENTER 13
#define TEC_TAB 9
#define TEC_BACKSPACE 8
#define TEC_ESC 27
#define TEC_DIR 1077
#define TEC_ESQ 1075
#define TEC_BAIXO 1080
#define TEC_CIMA 1072
#define TEC_DEL 1083
#define TEC_END 1079
#define TEC_INSERT 1082
#define TEC_HOME 1071
#define TEC_PAGE_UP 1073
#define TEC_PAGE_DOWN 1081


enum DOS_COLORS {
       BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
       LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
       LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };


void gotoxy(int x, int y);                               // move o cursor para determinada posição
void textcoloreback(int letras, int fundo);             // altera a cor da palavra e do fundo
int getTecla();                                         // server para usar as setas no menu


void Borda(int x, int y, int largura, int altura, int tipo, int sombra); // cria as bordas


int MenuBorda(int x, int y, char Opcoes[][21], int n);                   // cria o menu de opcoes horizontais
int MenuBordaVertical(int x, int y, char Opcoes[][21], int n);           // cria o menu de opcoes verticais


int Listagem(int x, int y, int largura, int altura, char Linhas[][101], int n); /* Cria um lista onde podemos ir para
                                                                                   baixo ou para cima */


void tipocursor (int cursor);            // altera o cursor


#endif // INTERFACE_H_INCLUDED
