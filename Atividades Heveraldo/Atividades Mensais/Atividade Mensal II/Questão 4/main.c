#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char A[31], B[31];
    int i, quant=0;

    printf("Digite as duas palavras: ");

    scanf("%s %s", A, B);

    for(i=0;i<strlen(A);i++)
    {
        if(A[i] == 'a')
            quant +=1;
    }

    for(i=0;i<strlen(B);i++)
    {
        if(B[i] == 'a')
            quant +=1;
    }

    printf("A quantidade de letras /a/ encontradas e: %d\n", quant);

    return 0;
}
