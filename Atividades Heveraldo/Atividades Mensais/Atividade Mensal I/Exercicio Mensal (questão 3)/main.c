#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, passagem, maior, menor, media, soma, Total;
    maior=0;
    soma=0;
    menor=999;

    for(i=0;i<50;i++)
    {
        scanf("%d", &passagem);

        if(passagem>maior){maior=passagem;}

        if(passagem<menor){menor=passagem;}

        soma = soma+passagem;
    }

    media = soma/i;

    printf("\no maior: %d\n", maior);
    printf("o menor: %d\n", menor);
    printf("a media: %d\n", media);
    printf("o total de passagens: %d\n", i);


    return 0;
}
