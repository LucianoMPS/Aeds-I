#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char A[10001];
    char B[10001];

    int teste, tam, quant, i, x;

    scanf("%d", &teste);

        while(teste--)
        {
            quant=0;
            x=0;

            scanf("%s %s", A, B);
            tam = strlen(A);

            for(i=0;i<tam;i++)
            {
               x = B[i] - A[i];

               if(x<0)
                  quant += x + 26;
               else
                  quant += x;
            }
            printf("%d\n", quant);

        }

    return 0;
}
