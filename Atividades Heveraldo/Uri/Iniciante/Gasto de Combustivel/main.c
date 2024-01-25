#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Tempo, Vm, Distancia;
    float Gasolina;

    scanf("%d %d", &Tempo, &Vm);

    Distancia = Vm * Tempo;

    Gasolina = Distancia/12.0;

    printf("%.3f\n", Gasolina);

    return 0;
}
