#include <stdio.h>
#include <stdlib.h>

int main()
{
   double Metade[100];
   double num;
   int i;


   scanf("%lf", &num);

   for(i=0; i < 100; i++)
   {

       Metade[i] = num;

       printf("N[%d] = %.4lf\n", i, num);

       num /= 2.0;

   }

    return 0;
}
