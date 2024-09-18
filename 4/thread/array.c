#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM 1000
#define NUM_THREADS 4
#define NUMERO_RICERCA 8

int numeri[NUM];

typedef struct
{
    int inizio;
    int fine;
} Intervallo;

// metodo per riempire l'array conn numeri casuali
void FillArray()
{
    srand(time(NULL)); // Cambio seme del random

    for (int i = 0; i < NUM; i++)
    {
        numeri[i] = rand() % 11; // Estremo massimo escluso
    }
}

void *ricerca(void *par)
{
    Intervallo *intervallo = (Intervallo *)par;

    for (int i = intervallo->inizio; i < intervallo->fine; i++)
    {
        if (numeri[i] == NUMERO_RICERCA)
        {
            printf("Il numero %d è presente in %d\n", NUMERO_RICERCA, i);
            pthread_exit(NULL); // Termina il thread corrente
        }
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];                   // array di thread
    int DivisioniArrayPerRicerca = NUM / NUM_THREADS; // calcolo parti di divisione dell'array
    Intervallo intervallo[NUM_THREADS];

    FillArray(); // riempio l'array

    // creazione ed esecuzione dei thread
    for (int i = 0; i < NUM_THREADS; i++)
    {
        intervallo[i].inizio = i * DivisioniArrayPerRicerca;     // calcolo dove cominciare la ricerca
        intervallo[i].fine = (i + 1) * DivisioniArrayPerRicerca; // calcolo dove finire la ricerca
        pthread_create(&threads[i], NULL, &ricerca, (void *)&intervallo[i]);
    }

    // aspetto la fine dell'esecuzione di tutti i thread
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
