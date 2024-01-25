#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double A, B, C, Delta, X1, X2;

    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);

    Delta = (B * B) - 4 * A * C;

    if(Delta > 0 && Delta != 0 && A != 0)
    {
        X1 = ((B * -1) + sqrt(Delta)) / (A * 2);
        X2 = ((B * -1) - sqrt(Delta)) / (A * 2);

        printf("R1 = %.5lf\n", X1);
        printf("R2 = %.5lf\n", X2);
    }
    else
        printf("Impossivel calcular\n");

    return 0;
}
