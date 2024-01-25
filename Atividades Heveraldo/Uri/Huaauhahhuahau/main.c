#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,k=0;
    char risada[51], vogais[51];

    scanf("%s", risada);

    for(i=0; i<strlen(risada);i++)
    {
        if(risada[i]== 'a' || risada[i]== 'e' || risada[i]== 'i' || risada[i]== 'o' || risada[i]== 'u')
        {
            vogais[k] = risada[i];
            k++;
        }
    }

    vogais[k] = '\0';

    for(i=0,j=strlen(vogais)-1; i < strlen(vogais); i++,j--)
    {
        if(vogais[i] != vogais[j])
        {
            printf("N\n");
            return 0;
        }
    }

    printf("S\n");

    return 0;
}
