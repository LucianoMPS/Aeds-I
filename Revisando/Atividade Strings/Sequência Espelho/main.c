#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T, in, fim, i, j, k;

    char sequencia[13000];

    scanf("%d", &T);

    for(i=0;i<T;i++)
    {
        scanf("%d", &in);
        scanf("%d", &fim);

        for(j=in;j<=fim;j++)
            printf("%d", j);

        for(j=fim;j>=in;j--)
        {
            sprintf(sequencia, "%d", j);


            for (k = strlen(sequencia)-1; k >= 0; k--)
                printf("%c", sequencia[k]);
        }
        printf("\n");

    }

    return 0;
}
