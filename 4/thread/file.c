#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

#define BUFFER_SIZE 1024

sem_t S_lettura, S_scrittura; // creazione di due semofori POSIX per sicronizzare lettura e scrittura
int n = 0;
char buffer[BUFFER_SIZE];

void *scrittura(void *fileDestinazione)
{
    FILE *dest_file = fopen((char *)fileDestinazione, "wb");
    if (dest_file == NULL)
    {
        perror("Errore nell'apertura del file di destinazione");
        exit(-1);
    }

    while (!feof(dest_file) || n > 0)
    {
        sem_wait(&S_lettura);   // aspetto che abbia letto dei dati dal file
        sem_wait(&S_scrittura); // aspetto dati per la scrittura

        if (n > 0)
        {
            fwrite(buffer, 1, n, dest_file); // Scrivo nel file di destinazione
        }
    }

    fclose(dest_file);

    pthread_exit(NULL);
}

void *lettura(void *arg)
{
    char *nomeFile = (char *)arg;
    printf("%s \n", nomeFile);
    FILE *src_file = fopen(nomeFile, "rb");
    if (src_file == NULL)
    {
        perror("Errore nell'apertura del file di origine");
        exit(-1);
    }

    while (n > 0)
    {
        sem_wait(&S_lettura);
        n = fread(buffer, 1, BUFFER_SIZE, src_file);
    }

    sem_post(&S_scrittura); // dico che ci sono dati per la scrittura
    sem_post(&S_lettura);   // dico che si può leggere

    fclose(src_file);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Numero di argomenti errato.\n");
        exit(-1);
    }

    pthread_t T_lettura, T_scrittura;
    char nFileOrigine[25], nFileDestinazione[25];

    strcpy(nFileOrigine,argv[1]);
    strcpy(nFileDestinazione,argv[2]);

    // inizializzazione dei semafori
    sem_init(&S_lettura, 0, 0);
    sem_init(&S_scrittura, 0, 0);

    pthread_create(&T_lettura, NULL, lettura, (void *)nFileOrigine);
    pthread_create(&T_scrittura, NULL, lettura, (void *)nFileDestinazione);

    pthread_join(T_lettura, NULL);   // Aspetta che il thread di lettura finisca
    pthread_join(T_scrittura, NULL); // Aspetta che il thread di scrittura finisca

    sem_destroy(&S_scrittura);
    sem_destroy(&S_lettura);

    printf("Operazione completata.\n");

    return 0;
}