#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


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


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int getTecla()
{
    int ch;
    ch = getch();
    if(ch == 224)
    {
        ch = getch() + 1000;
    }
    return ch;
}


int main(){


    int tecla, X = 37, i;


    while(1){
        gotoxy(X, 21);
        printf("   ^   ");
        gotoxy(X, 22);
        printf(" _-|-_ ");


        tecla = getTecla();


        if(tecla == 27) break;
        if(tecla == TEC_ESQ) X--;
        if(tecla == TEC_DIR) X++;
        if(tecla == ' '){
            for(i = 19; i > 0;i--){
                gotoxy(X, i);
                printf("   ^   ");
                gotoxy(X, i+1);
                Sleep(10);
                printf("       ");
            }
            gotoxy(X, i+1);
            Sleep(10);
            printf("       ");
        }
        if(X < 1) X = 1;
        if(X > 73) X = 73;
    }




    //kbhit();


    //Sleep(1000);




    return 0;
}
