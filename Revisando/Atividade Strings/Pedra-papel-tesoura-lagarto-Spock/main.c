#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int teste, i;

    char joga1[8];
    char joga2[8];

    scanf("%d", &teste);


    for(i=0;i<teste;i++)
    {
        scanf("%s", joga1);
        scanf("%s", joga2);

        if(strcmp(joga1, joga2)==0)
            printf("empate\n");

        else if((strcmp(joga1, "tesoura")==0 && strcmp(joga2, "papel")==0)

        || (strcmp(joga1, "papel")==0 && strcmp(joga2, "pedra")==0)

        || (strcmp(joga1, "pedra")==0 && strcmp(joga2, "lagarto")==0)

        || (strcmp(joga1, "lagarto")==0 && strcmp(joga2, "spock")==0)

        || (strcmp(joga1, "spock")==0 && strcmp(joga2, "tesoura")==0)

        || (strcmp(joga1, "tesoura")==0 && strcmp(joga2, "lagarto")==0)

        || (strcmp(joga1, "lagarto")==0 && strcmp(joga2, "papel")==0)

        || (strcmp(joga1, "papel")==0 && strcmp(joga2, "spock")==0)

        || (strcmp(joga1, "spock")==0 && strcmp(joga2, "pedra")==0)

        || (strcmp(joga1, "pedra")==0 && strcmp(joga2, "tesoura")==0))
        printf("rajesh\n");

        else
            printf("sheldon\n");
    }

    return 0;
}
