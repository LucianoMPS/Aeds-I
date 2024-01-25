#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double Dinheiro;
    float DinheiroDEC1;
    int DinheiroINT, DinheiroDEC2, N100=0, N50=0, N20=0, N10=0, N5=0, N2=0, N1=0, N050=0, N025=0, N010=0, N05=0, N01=0;

    scanf("%lf", &Dinheiro);

    DinheiroINT = trunc(Dinheiro); // esse é o truncamento
    DinheiroDEC1 = (Dinheiro - DinheiroINT)*100;
    DinheiroDEC2 = truncf(DinheiroDEC1);

    N100 = DinheiroINT/100;

    N50 = (DinheiroINT%100)/50;

    N20 = ((DinheiroINT%100)%50)/20;

    N10 = (((DinheiroINT%100)%50)%20)/10;

    N5 = ((((DinheiroINT%100)%50)%20)%10)/5;

    N2 = (((((DinheiroINT%100)%50)%20)%10)%5)/2;

    N1 = (((((DinheiroINT%100)%50)%20)%10)%5)%2;


    N050 = DinheiroDEC2/50;

    N025 = (DinheiroDEC2%50)/25;

    N010 = ((DinheiroDEC2%50)%25)/10;

    N05 = (((DinheiroDEC2%50)%25)%10)/5;

    N01 = (((DinheiroDEC2%50)%25)%10)%5;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", N100);
    printf("%d nota(s) de R$ 50.00\n", N50);
    printf("%d nota(s) de R$ 20.00\n", N20);
    printf("%d nota(s) de R$ 10.00\n", N10);
    printf("%d nota(s) de R$ 5.00\n", N5);
    printf("%d nota(s) de R$ 2.00\n", N2);

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", N1);
    printf("%d moeda(s) de R$ 0.50\n", N050);
    printf("%d moeda(s) de R$ 0.25\n", N025);
    printf("%d moeda(s) de R$ 0.10\n", N010);
    printf("%d moeda(s) de R$ 0.05\n", N05);
    printf("%d moeda(s) de R$ 0.01\n", N01);

    return 0;
}
