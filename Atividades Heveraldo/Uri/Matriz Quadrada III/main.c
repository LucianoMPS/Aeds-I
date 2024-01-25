#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, c=0, k;
    int Tam[101];


    while(1)
    {
        scanf("%d", &Tam[c]);

        if(Tam[c] == 0)
            break;

        c++;
    }

    for(k=0;k<c;k++)
    {
        int num = 1;
        int dobrado=1;
        int count=0;

        for(i=1;i<=Tam[k];i++)
        {
            num = dobrado;

            for(j=1;j<=Tam[k];j++)
            {
                if(j==Tam[k])
                {
                    printf("%d", num);
                    printf("\n");
                }

                else
                    printf("%d ", num);

                if(i==Tam[k] && j==Tam[k])
                    printf("\n");

                num *= 2;
            }
            count++;
            dobrado = 1 * pow(2,count);
        }
    }


    return 0;
}
