#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char senha[9];
    senha[8] = '\0';

    printf("Digite a senha, com no maximo 8 digitos: ");
    scanf(" %[^\n]", senha);


    if(strlen(senha) < strlen("Deus 123"))
    printf("Poucos caractes\n");

    else if(strcmp(senha, "Deus 123") == 0)
        printf("Acesso Permitido\n");

    else
    {
        printf("Acesso negado\n");
        printf("Ta achando que aqui e a casa da mae Joana?\n");
    }

    return 0;
}
