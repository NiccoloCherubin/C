#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define NUM 100

int numeroDaCercare = 8;
int numeri[NUM];

void FillArray()
{
    srand(time(NULL)); //cambio seme del random

    for(int i = 0; i < NUM; i++)
    {
        numeri[i] = rand() % 11; //estremo massimo escluso
    }
}
void *ricerca(void *par)
{
    int *numero = (int *)par;
    int rangeRicerca = *numero + NUM / 2;

    for (int i = *numero; i < rangeRicerca; i++)
    {
        if (numeri[i] == numeroDaCercare)
        {
            printf("Il numero %d è presente in %d\n", numeroDaCercare, i);
            exit(0);
        }
    }

    pthread_exit(NULL);
}
int main()
{

    pthread_t Ricerca1;
    pthread_t Ricerca2;
    pthread_t Ricerca3;
    pthread_t Ricerca4;

    FillArray();

    pthread_create(&Ricerca1, NULL, &ricerca, 0);

    int supp = NUM/2; // variabile di supporto

    pthread_create(&Ricerca2, NULL, &ricerca, &supp);

    pthread_join(Ricerca1, NULL);

    return 0;
}