#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    if (mkfifo("myfifo1", 0777) == -1) // nome, permessi (7 = 111)
    {
        if (errno != EEXIST) // controllo degli errori
        {
            perror("Errore");
            exit(-1);
        }
    }

    // apertura fifo
    int fd = open("myfifo1", O_WRONLY); // sarà uguale ad 1 perché siamo in scrittura
    printf("FIFO aperta \n");

    int x = 90;
    if (write(fd, &x, sizeof(x)) == -1) // write() restituisce il numero di byte scritti
    {
        perror("Errore scrittura");
        return 1;
    }
    printf("Scritto tutto nella fifo\n");
    close(fd); // chiuso fifo
    return 0;
}