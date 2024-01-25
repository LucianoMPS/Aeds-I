#include <stdio.h>
#include <stdlib.h>

double CalculoDeRenda(float RendaC)
{
    double Valor;

    if(RendaC <= 2000.00)
        Valor = 0;

    if(RendaC > 2000.00 && RendaC <= 3000.00)
        Valor = (RendaC - 2000.00) * 0.08;

    if(RendaC > 3000.00 && RendaC <= 4500.00)
        Valor = (1000.00 * 0.08) + ((RendaC - 3000.00) * 0.18);

    if(RendaC > 4500.00)
        Valor = (1000.00 * 0.08) + (1500.00 * 0.18) + ((RendaC - 4500.00) * 0.28);

    return Valor;

}

int main()
{
    double Imposto_Renda;
    float Renda;

    scanf("%f", &Renda);

    Imposto_Renda = CalculoDeRenda(Renda);

    if(Imposto_Renda == 0)
        printf("Isento\n");
    else
        printf("R$ %.2lf\n", Imposto_Renda);

    return 0;
}
