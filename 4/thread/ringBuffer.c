#include <stdio.h>
#include <pthread.h>

#define BUFFER_DIM 1024
#define BUFFER_SIZE 64

struct BUFFER
{
    unsigned char buffer[BUFFER_DIM];
    int n;
};

struct BUFFER ring_buffer[BUFFER_SIZE];
int eof = 0;
int read_index = 0;
int write_index = 0;
int N_block = 0;

void *leggi(void *arg)
{
    FILE *file = (FILE *)arg;

    while (!feof(file))
    {
        while (N_block >= BUFFER_SIZE) // attesa per quando buffer pieno
        {

        } 
            
        int n = fread(ring_buffer[write_index].buffer, 1, BUFFER_DIM, file);

        if (n > 0)
        {
            ring_buffer[write_index].n = n;
            write_index 
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t T_lettura, T_scrittura;
    FILE *origine, *destinazione;

    if (argc != 3)
    {
        printf("Numero argomenti errati \n");
        exit(-1);
    }

    origine = fopen(argv[1], "r");

    if (origine == NULL)
    {
        printf("Errore apertura file di origine \n");
        exit(-1);
    }

    destinazione = fopen(argv[2], "w");
    if (destinazione == NULL)
    {
        printf("Errore apertura file d'origine \n");
        exit(-1);
    }
    return 0;
}