#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Argomenti insufficenti\n");
        exit(-1);
    }
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
        close(fd[0]); // chiuso pipe
    }
    else
    {
        int p1;
        // Processo padre
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
        close(fd[1]); // chiuso pipe
        p1 = fork(); // nuova fork
        if (p1 < 0)
        {
            printf("Errore nella creazione della fork \n");
            exit(-1);
        }
        if (p1 == 0)
        {
            int cont = 0;
            // figlio 2 conta i caratteri nel file
            destinazione = fopen("destinazione.txt", "r");
            while (n = read(fd[0], buffer, BUFFER_SIZE) > 0)
            {
                for (int i = 0; i < BUFFER_SIZE; i++)
                {
                    if (buffer[i] == argv[1][0]) // prendo il primo carattere della stringa
                    {
                        cont++;
                    }
                }
            }
            printf("Il carattere %c nel file è presente %d volte\n", argv[1][0], cont);
        }
    }

    return 0;
}
