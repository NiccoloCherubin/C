#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO1 "shell1_to_shell2_fifo"
#define FIFO2 "shell2_to_shell1_fifo"

int main()
{
    int fd1, fd2;
    char input[256];

    // Creazione delle FIFO
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    // Fork
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {                        // Processo figlio (lettura)
        close(STDIN_FILENO); // Chiudi stdin nel processo figlio

        // Apertura della FIFO in modalità di lettura
        fd2 = open(FIFO2, O_RDONLY);

        while (1)
        {
            // Lettura dalla FIFO
            read(fd2, input, sizeof(input));
            printf("Shell 1: %s", input);

            // Controllo se l'input è "HALT" per terminare la chat
            if (strcmp(input, "HALT\n") == 0)
            {
                break;
            }
        }

        // Chiusura della FIFO
        close(fd2);
        exit(EXIT_SUCCESS);
    }
    else
    { // Processo padre (scrittura)

        // Apertura della FIFO in modalità di scrittura
        fd1 = open(FIFO1, O_WRONLY);

        while (1)
        {
            // Lettura input dalla shell
            printf("Shell 2: ");
            fgets(input, sizeof(input), stdin);

            // Scrittura dell'input nella FIFO
            write(fd1, input, strlen(input));

            // Controllo se l'input è "HALT" per terminare la chat
            if (strcmp(input, "HALT\n") == 0)
            {
                break;
            }
        }

        // Chiusura della FIFO
        close(fd1);
    }

    // Rimozione delle FIFO
    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}
