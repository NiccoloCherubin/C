#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 2048

int main()
{
    FILE *origine;
    FILE *destinazione;
    int fd[2]; // file descriptor per la pipe
    int p;
    char buffer[BUFFER_SIZE];
    int n;
    // Creazione della pipe
    if (pipe(fd) == -1)
    {
        printf("Errore nella creazione della pipe");
        exit(-1);
    }

    // Creazione del processo figlio
    p = fork();
    if (p == -1)
    {
        perror("Errore nella fork");
        exit(-1);
    }

    if (p == 0)
    {                 // Processo figlio
        close(fd[1]); // chiuso scrittura
        destinazione = fopen("destinazione.txt", "w");
        if (destinazione == NULL)
        {
            printf("Errore nell'apertura del file di destinazione");
            exit(-1);
        }
        while ((n = read(fd[0], buffer, BUFFER_SIZE)) > 0)
        {
            fwrite(buffer, 1, n, destinazione);
        }

        fclose(destinazione);
        close(fd[0]); // Chiude l'estremità di lettura della pipe nel processo figlio
    }
    else
    {                 // Processo padre
        close(fd[0]); // chiuso lettura       
        origine = fopen("origine.txt", "r");
        if (origine == NULL)
        {
            printf("Errore nell'apertura del file di origine");
            exit(-1);
        }
        while ((n = fread(buffer, 1, BUFFER_SIZE, origine)) > 0)
        {
            write(fd[1], buffer, n);
        }

        fclose(origine);
        close(fd[1]); // Chiude l'estremità di scrittura della pipe nel processo padre
    }

    return 0;
}
