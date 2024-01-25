#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,j,a,b,c,n;
   a = 0;
   b = 1;

   scanf("%d", &n);

   for(i=0;i < n;i++)
   {
       c = a + b;

       for(j=0;j < 1;j++)
       {
       if(i < n )
         printf("%d ", a);
       else
        if(i ==n)
         printf("%d", a);
       }

       a = b;
       b = c;
   }

    return 0;
}
