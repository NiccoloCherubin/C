#include <stdio.h>
// Dopo aver letto N numeri reali calcolare la somma e la media dei numeri pari maggiori di 5 visualizzando a video i risultati .
void main()
{
    int numero;
    float numeri, somma = 0, media, i = 0;
    do
    {
        printf("Quanti numeri vuoi inserire? \n");
        scanf("%f", &numeri);
    } while (numeri <= 0);
    do
    {
        printf("Inserire numero \n");
        scanf("%d", &numero);
        if (numero % 2 == 0)
        {
            if (numero > 5)
            {
                somma = somma + numero;
            }
        }
        else
        {
            printf(" il numero inerito non è pari e non verrà preso in considerazione per il calcolo della somma");
        }

        numeri--;
        i++;
    } while (numeri != 0);
    media = somma / i;
    printf("La somma dei numeri inseriti equivale a %f", somma);
    printf("La media dei numeri inseriti equivale a %f", media);
}