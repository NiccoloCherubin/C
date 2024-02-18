#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    // dichiarazione variabili
    int somma = 0;
    int fd;
    int numeri[5];

    // apertura pipe
    fd = open("sum", O_RDONLY);

    // lettura da pipe
    for (int i = 0; i < 5; i++)
    {
        if (read(fd, &numeri[i], sizeof(int)) == -1)
        {
            printf("Errore nella lettura da pipe \n");
            exit(-1);
        }
    }

    // chiusura fifo
    close(fd);

    // calcolo somma
    for (int i = 0; i < 5; i++)
    {
        somma += numeri[i];
    }

    // stampo somma
    printf("Somma dei numeri: %d \n", somma);

    return 0;
}