#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

    int limite1, limite2, n, somma = 0, i = 0;
    const short min = 30, max = 50;
    // inserimento limiti
    if (argc == 3)
    {
        if (atoi(argv[1]) < min || atoi(argv[1]) > max) // atoi converte in intero
        {
            printf("Il primo limite non è compreso tra i 30 e 50\n");
            return -1;
        }
        else if ((atoi(argv[2]) < min || atoi(argv[2]) > max))
        {
            printf("Il secondo limite non è compreso tra i 30 e 50 \n");
            return -1;
        }
    }
    else
    {
        printf("non hai inserito abbastanza argomenti \n");
        return -1;
    }
    limite1 = atoi(argv[1]);
    limite2 = atoi(argv[2]);

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
    // stampa della somma dei numeri
    printf("La somma dei numeri compresi tra i limiti è uguale a %d", somma);

    return 0;
}