#include <stdio.h>
#include <stdlib.h>

int main()
{
   float Num;

   scanf("%f", &Num);

   if(Num >= 0.0 && Num <= 25.0)
        printf("Intervalo [0,25]\n");

   else if(Num <= 50.0)
        printf("Intervalo [25,50]\n");

   else if(Num <= 75.0)
        printf("Intervalo [50,75]\n");

   else if(Num <= 100)
        printf("Intervalo [75,100]\n");

   else
        printf("Fora de Intervalo\n");

    return 0;
}
