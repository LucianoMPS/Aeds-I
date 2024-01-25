#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k, tam;
    char palavra[101];

    while(scanf("%s", palavra)!=EOF)
    {
        tam = strlen(palavra);

            for(i=0;i<=strlen(palavra)-1;i++)
            {
               for(j=0;j<i;j++)
                  printf(" ");

               for(k=0;k<tam;k++)
               {
                   printf("%c", palavra[k]);

                   if(k<tam-1)
                     printf(" ");
               }

               tam--;
               printf("\n");

            }

        printf("\n");
    }

    return 0;
}
