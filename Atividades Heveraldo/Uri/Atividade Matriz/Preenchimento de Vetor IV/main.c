#include <stdio.h>
#include <stdlib.h>
/* Neste problema voc� dever� ler 15 valores coloc�-los em 2 vetores
conforme estes valores forem pares ou �mpares. S� que o tamanho de cada um dos
dois vetores � de 5 posi��es. Ent�o, cada vez que um dos dois vetores encher, voc�
dever� imprimir todo o vetor e utiliz�-lo novamente para os pr�ximos n�meros que forem lidos.
Terminada a leitura, deve-se imprimir o conte�do que restou em cada um dos dois vetores,
imprimindo primeiro os valores do vetor impar. Cada vetor pode ser preenchido
tantas vezes quantas for necess�rio. */

int main()
{
   int par[5];
   int impar[5];

   int num, i, j;

   int qpar=0, qimp=0;


   for(i=0; i<15; i++)
   {
       scanf("%d", &num);

       if(num % 2 == 0)
       {
           par[qpar] = num;
           qpar++;

           if(qpar == 5)
           {
               for(j=0;j<5;j++)
                printf("par[%d] = %d\n", j, par[j]);

               qpar = 0;
           }

       }

       else
       {
           impar[qimp] = num;
           qimp++;

            if(qimp == 5)
           {
               for(j=0;j<5;j++)
                printf("impar[%d] = %d\n", j, impar[j]);

                qimp = 0;
           }

       }
   }

   for(j=0;j<qimp;j++)
            printf("impar[%d] = %d\n", j, impar[j]);

   for(j=0;j<qpar;j++)
            printf("par[%d] = %d\n", j, par[j]);

    return 0;
}
