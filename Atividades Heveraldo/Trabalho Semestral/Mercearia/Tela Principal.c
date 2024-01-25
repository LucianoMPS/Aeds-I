#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interface.h"


void TelaPrincipal()
{
    system("cls"); /* Limpa a tela */

    textcoloreback(WHITE, RED);
    Borda(0, 0, 29, 24, 1, 0);


    textcoloreback(WHITE, BLACK);


    Borda(1,1,27,2,0,0);
    gotoxy(11, 2); printf("Mercearia");
    gotoxy(7, 3); printf("Oliveira & Morais");


    textcoloreback(WHITE, RED);
}





