#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    // dichiarazione variabile
    int numeri[5];
    int fd;
    // apertura fifo
    fd = open("sum", O_WRONLY);
    printf("Aperto fifo \n");

    // generazione numeri random
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        numeri[i] = rand() % 100; // da 0 a 99 incluso
    }

    // scrittura numeri sulla fifo
    for (int i = 0; i < 5; i++)
    {

        if (write(fd, numeri, sizeof(numeri[i])) == -1)
        {
            printf("Scrittura su fifo fallita \n");
            exit(-1);
        }
    }

    // chiusura fifo
    close(fd);

    // messaggio di riuscita del programma
    printf("Scrittura avvenuta con successo \n");

    return 0;
}