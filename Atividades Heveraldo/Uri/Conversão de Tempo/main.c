#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Tempo_Seg, Seg, Min, Hor;

    scanf("%d", &Tempo_Seg);

    Hor = Tempo_Seg/3600;

    Min = (Tempo_Seg%3600)/60;

    Seg = (Tempo_Seg%3600)%60;

    printf("%d:%d:%d\n", Hor, Min, Seg);

    return 0;
}
