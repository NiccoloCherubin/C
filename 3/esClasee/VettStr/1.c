#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int array[4];
    int swap; // per fare lo scambio dopo
    // inserimento valori
    for (int i = 0; i < 4; i++) // la dimensione si calcola facendo il size of dell'array fratto quella del primo elemento
    {
        printf("Inserisci il %d numero \n", i + 1);
        scanf("%d", &array[i]);
    }
    // ordinamento valori
    for (int i = 0; i < 4 - 1; i++) // - 1 per non andare out of index
    {
        swap = array[i];
        array[i] = array[i + 1];
        array[i + 1] = swap;
    }
    // stampa vettore
    printf("Array ordinato \n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d \n", array[i]);
    }
    return 0;
}