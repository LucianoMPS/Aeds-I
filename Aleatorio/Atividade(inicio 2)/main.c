#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, horas;
    float ganho;
    float salario;

    scanf("%d", &numero);
    scanf("%d", &horas);
    scanf("%f", &ganho);


    salario = (horas * ganho);

    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2lf\n", salario);

}
