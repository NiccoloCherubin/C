#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFFER_DIM 4
void main()
{
    int n;             // inserito dall'utente da riga di comando e deve essere ricercato nell'array
    int numeri[10000]; // array da 10k
    FILE *destinazione;
    unsigned char buffer[BUFFER_DIM];

    for (int i = 0; i < 10000; i++)
    {
        numeri[i] = rand() % 501; // genera numero casuale
    }
    destinazione = fopen("padre.txt", "w");
    for (int i = 0; i < 10000; i++)
    {
        fprintf(destinazione, "%d: %d \n", i, numeri[i]);
    }
}
