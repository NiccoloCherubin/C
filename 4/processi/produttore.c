#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

int spawn(char program[], char *argument[])
{
    int p;
    printf("Sono Spawn. Mio PID = %d", getpid());
    p = fork();
    if (p < 0)
    {
        exit(-1);
    }
    if (p > 0) // padre
    {
        printf("Sono il padre in spawn. Mio PID = %d", getpid());
        exit(0);
    }
    else // figlio
    {
        printf("Sono il figlio in spawn. Mio PID = %d", getpid());
        execv(program, argument);

        printf("errore nell'esucuzione del processo con execv");
        abort();
    }
    return 0;
}
int main(int argc, char *argv[])
{
    FILE *file;
    int fifo;
    unsigned char buffer[1024];
    int n;
    char *arg[3];
    int a;

    printf("Sono il padre. Mio PID = %d", getpid());

    arg[0] = (char *)malloc(strlen("./consumatore") + 1);
    strcpy(arg[0], "./consumatore");

    arg[1] = (char *)malloc(strlen(argv[2]) + 1);
    strcpy(arg[1], argv[2]);

    arg[2] = NULL;

    if (spawn("./consumatore", arg) < 0)
    {
        printf("Errore creazione figlio");
        free(arg[0]);
        free(arg[1]);
        return 0;
    }
    if (mkfifo("my_fifo", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Errore fifo");
        }
        return 0;
    }
    fifo = open("my_fifo", O_WRONLY);

    if (fifo < 0)
    {
        printf("errore fifo");
    }
    file = fopen(argv[1], "rb");
    if(file == NULL)
    {
        printf("Errore file");
        free(arg[0]);
        free(arg[1]);
        return 0;
    }
    while (!feof(file))
    {
        /* code */
    }
    
}
