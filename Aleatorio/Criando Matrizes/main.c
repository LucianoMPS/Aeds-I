#include <stdio.h>
#include <stdlib.h>

// questão 2
int main()
{
    char Nome1[51], Nome2[51], Nome3[51];
strcpy(Nome1, "Maria");
strcpy(Nome2, "Jose");
strcpy(Nome3, "Vieira");
if(strcmp(Nome1, "Maria") == 0){
strcpy(Nome1, "Mario ");
}
else{
strcpy(Nome1, "Jose ");
}
strcat(Nome1, "de ");
strcat(Nome1, "Jesus ");
strcat(Nome1, Nome3);
printf("\n\n%s",Nome1);
printf("\n\n%d\n\n",strlen(Nome1));

return 0;
}
