#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Tempo, Segundos=0, Minutos=0, Horas=0;

    scanf("%d", &Tempo);

    if(Tempo >= 3600)
        Horas = Tempo/3600;

    if(Tempo >= 60){
        Minutos = (Tempo - Horas * 3600)/60;
        Segundos = Tempo % 60;
    }

    if(Tempo < 60)
        Segundos = Tempo;

    printf("%d:%d:%d\n", Horas, Minutos, Segundos);

    return 0;
}
