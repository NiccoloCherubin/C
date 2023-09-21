#include <stdio.h>
int main(int argc, char *argv[])
{

    int limite1, limite2, n, somma = 0, i = 0;
    const short min = 30, max = 50;
    // inserimento limiti
    do
    {
        printf("Inserire il primo limite compreso tra 30 e 50\n");
        scanf("%d", &limite1);
    } while (limite1 < min || limite1 > max);
    do
    {
        printf("Inserire il secondo limite compreso tra 30 e 50\n");
        scanf("%d", &limite2);
    } while (limite2 < min || limite2 > max);
    // confronto e swap limiti e rendo limite1 sempre il minore
    if (limite1 >= limite2)
    {
        i = limite1;
        limite1 = limite2;
        limite2 = i;
    }
    // inserimento numeri
    for (int i = 0; i < 5; i++)
    {
        printf("Inserire %d numero \n", i + 1);
        scanf("%d", &n);
        if (n >= limite1 && n <= limite2)
        {
            somma += n;
        }
        else
        {
            printf("Il numero non è compreso tra i limiti \n");
        }        
    }
    //stampa della somma dei numeri
    printf("La somma dei numeri compresi tra i limiti è uguale a %d", somma);

    return 0;
}