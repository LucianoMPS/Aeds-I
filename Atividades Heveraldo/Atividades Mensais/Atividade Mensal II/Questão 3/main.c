#include <stdio.h>
#include <stdlib.h>

int main()
{
    int conjunto[3][10];
    int n=0,i,j;

    printf("digite o primeiro valor da matriz: ");
    scanf("%d", &n);

    for(i=0;i<3;i++)
        for(j=0;j<10;j++){
            conjunto[i][j] = n;
            n += 10;
        }

    for(i=0;i<3;i++)
            for(j=0;j<10;j++){
               if(j == 9)
                  printf("%d\n", conjunto[i][j]);
               else
                  printf("%d ", conjunto[i][j]);

            }

    return;
}
