#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, QuantLeds=0, Quant;
    char NumChar[1000001];

    scanf("%d", &Quant);

    for(i=0;i<Quant;i++)
    {
        scanf("%s", NumChar);

        for(j=0;j<strlen(NumChar);j++)
        {

        if(NumChar[j] == '0')
            QuantLeds += 6;

        else if(NumChar[j] == '1')
            QuantLeds += 2;

        else if(NumChar[j] == '2')
            QuantLeds += 5;

        else if(NumChar[j] == '3')
            QuantLeds += 5;

        else if(NumChar[j] == '4')
            QuantLeds += 4;

        else if(NumChar[j] == '5')
            QuantLeds += 5;

        else if(NumChar[j] == '6')
            QuantLeds += 6;

        else if(NumChar[j] == '7')
            QuantLeds += 3;

        else if(NumChar[j] == '8')
            QuantLeds += 7;

        else if(NumChar[j] == '9')
            QuantLeds += 6;

        }

        printf("%d leds\n", QuantLeds);
        QuantLeds = 0;
    }


    return 0;
}

