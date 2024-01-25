#include <stdio.h>
#include <stdlib.h>

int main()
{
   int N, num, i;

   scanf("%d", &N);

   int Omenor[N];

   int menor = 99999, posicao = 0;

   for(i=0;i<N;i++)
   {
       scanf("%d", &num);
       Omenor[i] = num;

       if(Omenor[i] < menor)
       {
           menor = num;
           posicao = i;
       }

   }

   for(i=0;i<N;i++)
   {
       if(Omenor[i] == menor)
       {
           posicao = i;
           break;
       }

   }

   printf("Menor valor: %d\n", menor);
   printf("Posicao: %d\n", i);

    return 0;
}

