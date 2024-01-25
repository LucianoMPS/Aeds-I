#include <stdio.h>
#include <stdlib.h>

int main()
{
   int Odobro[10];
   int i, sequencia;


   scanf("%d", &sequencia);

   for(i=0; i < 10; i++)
   {

       Odobro[i] = sequencia;

       printf("N[%d] = %d\n", i, sequencia);

       sequencia *= 2;

   }

    return 0;
}
