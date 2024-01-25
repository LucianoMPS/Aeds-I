#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo(int numero)
{
    int i;

    for(i=2;i<numero;i++)
        {
          if(sqrt(numero) == numero * numero){
                return 0;
          }



          if(numero%i == 0)
          {
              return 0;
          }

        }

    return 1;
}

int main()
{
    int n, t, i;

    scanf("%d", &t);

    for(i=0;i<t; i++)
    {
        scanf("%d", &n);

        if(primo(n))
            printf("Prime\n");
        else
            printf("Not Prime\n");
    }

    return 0;
}
