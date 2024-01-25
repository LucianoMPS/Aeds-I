#include <stdio.h>
#include <stdlib.h>

int temp(int PA, int PB, double GA, double GB)
{
   int t;
   t = 0;

   while(PA <= PB)
      {
        PA *= (GA/100) + 1;
        PB *= (GB/100) + 1;

        t += 1;
        if(t > 100) break;
      }
   return t;
}

int main()
{
   int T, i, tempo;
   int PA, PB;
   PA = 0;
   PB = 0;

   double GA, GB;

   scanf("%d", &T);

   for(i=1;i<=T;i++)
   {
      scanf("%d %d", &PA, &PB);
      scanf("%lf %lf", &GA, &GB);

      tempo = temp(PA,PB,GA,GB);

      if(tempo > 100)
        printf("Mais de um seculo.\n");
      else if(tempo <= 100)
        printf("%d anos.\n", tempo);
   }

    return 0;
}
