#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ganhou(int Rafael, int Beto, int Carlos)
{
    if(Rafael > Beto && Rafael > Carlos)
        printf("Rafael ganhou\n");

    else if(Beto > Rafael && Beto > Carlos)
        printf("Beto ganhou\n");

    else if(Carlos > Rafael && Carlos > Beto)
        printf("Carlos ganhou\n");
}

int main()
{
    int N,i,x,y;
    int Rafael, Beto, Carlos;

    scanf("%d", &N);

    for(i=0;i<N;i++)
    {
        scanf("%d %d", &x, &y);

        Rafael = pow((3 * x), 2) + pow(y, 2);

        Beto = (2 * (pow(x,2))) + pow((5 * y), 2);

        Carlos = (-100 * x) + pow(y,3);

        ganhou(Rafael,Beto,Carlos);
    }

    return 0;
}
