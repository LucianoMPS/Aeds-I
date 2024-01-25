#include <stdio.h>
#include <stdlib.h>

double imposto(float salario)
{
    double valor;

    if(salario <= 2000.00)
        valor = 0;

    if(salario > 2000.00 && salario <= 3000.00 )
        valor = (salario - 2000.00) * 0.08;

    if(salario > 3000.00 && salario <= 4500.00)
        valor = 1000.00 * 0.08 + (salario - 3000.00) * 0.18;

    if(salario > 4500.00)
        valor = 1000.00 * 0.08 + 1500.00 * 0.18 + (salario - 4500.00) * 0.28;

    return valor;
}

int main()
{
    float salario;
    double N;

    scanf("%f", &salario);
    N = imposto(salario);

    if(N == 0)
       printf("Isento\n");

    else
       printf("R$ %.2lf\n", N);

    return 0;
}

