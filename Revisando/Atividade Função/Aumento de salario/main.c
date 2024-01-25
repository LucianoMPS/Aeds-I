#include <stdio.h>
#include <stdlib.h>

float calculo(float valor)
{
float X;

if(valor >= 0 && valor <= 400.00)
X = valor * 0.15;

else if(valor >= 400.01 && valor <= 800.00)
X = valor * 0.12;

else if(valor >= 800.01 && valor <= 1200.00)
X = valor * 0.10;

else if(valor >= 1200.01 && valor <= 2000.00)
X = valor * 0.07;

else if(valor > 2000)
X = valor * 0.04;

return X;
}

int main()
{
    int percentual;
    float valor, reajuste, salario;
    scanf("%f", &valor);

    reajuste = calculo(valor);
    salario = valor + reajuste;

    if(valor >= 0 && valor <= 400.00)
    percentual = 15;

    else if(valor >= 400.01 && valor <= 800.00)
    percentual = 12;

    else if(valor >= 800.01 && valor <= 1200.00)
    percentual = 10;

    else if(valor >= 1200.01 && valor <= 2000.00)
    percentual = 7;

    else if(valor > 2000)
    percentual = 4;

printf("Novo salario: %.2f\n", salario);
printf("Reajuste ganho: %.2f\n", reajuste);
printf("Em percentual: %d%%\n", percentual);

    return 0;
}
