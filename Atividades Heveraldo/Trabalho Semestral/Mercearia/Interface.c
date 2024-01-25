#include "Interface.h"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Borda(int x, int y, int largura, int altura, int tipo, int sombra)
{
    int i, j;
    char C[][6] = {"\xda\xbf\xc0\xd9\xc4\xb3" ,
                    "\xc9\xbb\xc8\xbc\xcd\xba"};
    gotoxy(x, y);
    printf("%c", C[tipo][0]);
    for(i = 0; i < largura; i++){
        printf("%c", C[tipo][4]);
    }
    printf("%c", C[tipo][1]);
    for(j = 0; j < altura; j++){
        gotoxy(x, y+j+1);
        printf("%c", C[tipo][5]);
        for(i = 0; i < largura; i++){
            printf(" ");
        }
        printf("%c", C[tipo][5]);
    }
    gotoxy(x, y+j+1);
    printf("%c", C[tipo][2]);
    for(i = 0; i < largura; i++){
        printf("%c", C[tipo][4]);
    }
    printf("%c", C[tipo][3]);

}


int MenuBorda(int x, int y, char Opcoes[][21], int n)
{
    int i, Opcao = 0, Tecla;
    for(i = 0; i < n; i++){
        Borda(x+15*i, y, 12, 1, 0, 0);
        gotoxy(x+1+15*i, y + 1); printf("%s", Opcoes[i]);
    }
    while(1){
        Borda(x+15*Opcao, y, 12, 1, 1, 0);
        gotoxy(x+1+15*Opcao, y+1); printf("%s", Opcoes[Opcao]);
        Tecla = getTecla();
        if(Tecla == TEC_ESC) {
            Opcao = -1;
            break;
        }
        if(Tecla == TEC_ENTER) return Opcao;
        Borda(x+15*Opcao, y, 12, 1, 0, 0);
        gotoxy(x+1+15*Opcao,y+1); printf("%s", Opcoes[Opcao]);
        if(Tecla == TEC_ESQ) Opcao--;
        if(Tecla == TEC_DIR) Opcao++;
        if(Opcao < 0) Opcao = n-1;
        if(Opcao > n-1) Opcao = 0;
    }
}


int MenuBordaVertical(int x, int y, char Opcoes[][21], int n)
{
    int i, Opcao = 0, Tecla;
    tipocursor(0);
    for(i = 0; i < n; i++){
        Borda(x, y+4*i, 12, 1, 0, 0);
        gotoxy(x+1, y + 1+4*i); printf("%s", Opcoes[i]);
    }
    while(1){
        Borda(x, y+4*Opcao, 12, 1, 1, 0);
        gotoxy(x+1, y+1+4*Opcao); printf("%s", Opcoes[Opcao]);
        Tecla = getTecla();
        if(Tecla == TEC_ESC) {
            Opcao = -1;
            break;
        }
        if(Tecla == TEC_ENTER) break;
        Borda(x, y+4*Opcao, 12, 1, 0, 0);
        gotoxy(x+1,y+1+4*Opcao); printf("%s", Opcoes[Opcao]);
        if(Tecla == TEC_CIMA) Opcao--;
        if(Tecla == TEC_BAIXO) Opcao++;
        if(Opcao < 0) Opcao = n-1;
        if(Opcao > n-1) Opcao = 0;
    }
    tipocursor(1);
    return Opcao;
}


int getTecla()
{
    int ch;
    ch = getch();
    if(ch == 224){
        ch = getch() + 1000;
    }
    return ch;
}


void textcoloreback (int letras, int fundo)
{
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (fundo << 4));
}


int Listagem(int x, int y, int largura, int altura, char Linhas[][101], int n)
{
    int i, Opcao = 1, Tecla, Primeiro = 0;

    textcoloreback(BLACK, WHITE);                 /* altera a cor da janela */
    Borda(x, y, largura, altura, 0, 0);
    gotoxy(x+1, y+1); printf("%s", Linhas[0]);

    for(i = Primeiro + 1; i <= n && i < altura; i++){
        gotoxy(x+1, y+i+1); printf("%s", Linhas[i]);
    }
    while(1){
        textcoloreback(WHITE, BLACK);    /* troca a cor da linha selecionada*/
        gotoxy(x+1, y+Opcao+1-Primeiro); printf("%s", Linhas[Opcao]);

        Tecla = getTecla();

        textcoloreback(BLACK, WHITE);    /* troca a cor das linhas percorridas */
        gotoxy(x+1, y+Opcao+1-Primeiro); printf("%s", Linhas[Opcao]);

        if(Tecla == TEC_ESC) {
            Opcao = -1;
            break;
        }
        if(Tecla == TEC_ENTER) break;
        if(Tecla == TEC_BAIXO) Opcao++;
        if(Tecla == TEC_CIMA) Opcao--;
        if(Opcao < 1) Opcao = 1;
        if(Opcao > n) Opcao = n;

        if(Opcao >= Primeiro + altura){
            Primeiro++;
            for(i = 1; i <= n && i < altura; i++){
                gotoxy(x+1, y+i+1); printf("%*s", -largura, Linhas[i+Primeiro]);
            }
        }
        if(Opcao <= Primeiro){
            Primeiro--;
            for(i = 1; i <= n && i < altura; i++){
                gotoxy(x+1, y+i+1); printf("%*s", -largura, Linhas[i+Primeiro]);
            }
        }

    }
    textcoloreback(WHITE, RED);   /* altera a cor do plano de fundo do console */
    return Opcao;
}


void tipocursor (int cursor)
{
    HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CURSOR;

    BOOL result;

    CURSOR.dwSize = 1;
    if(cursor == 0)
        CURSOR.bVisible = FALSE;
    else
        CURSOR.bVisible = TRUE;
    result=SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}
