#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define BUFSIZE 1024 // dimensione del buffer
int main()
{
    int p;
    int fd[2]; // file descriptor conosciuto da padre e da figlio. Creare pipe prima di forkare.
    int status;
    if (pipe(fd) == -1) // creazione pipe e controllo errore.
    {
        printf("Errore creazione pipe");
        exit(-1);
    }
    p = fork();
    // padre che comunica con il figlio.
    if (p == 0) // figlio
    {
        char buffer[BUFSIZE]; // buffer con il contenuto da stampare.
        close(fd[1]); // chiuso scrittura (entrata).
        printf("Sono il figlio PID= %d PPID= %d \n", getpid(), getppid());
        int n = read(fd[0], buffer, BUFSIZE); // n = ultima posizione della stringa. Funge da wait. Canale sincorno.
        if (n == -1)
        {
            printf("Errore lettura");
            exit(-1);
        }
        close(fd[0]);     // chiuso lettura (uscita).
        buffer[n] = '\0'; // aggiunto carfattere terminatore.
        printf("%s\n", buffer);
    }
    else if (p > 0) // padre
    {
        close(fd[0]); // chiuso lettura (uscita).
        printf("Sono il padre PID = %d \n", getpid());
        const char *messaggio = "Ciao figlio, sono il padre"; // messaggio da stampare.
        if (write(fd[1], messaggio, strlen(messaggio)) == -1) // scrittura su pipe e controllo errore.
        {
            printf("Errore scrittura");
            exit(-1);
        }
        close(fd[1]);  // chiuso la pipe.
        wait(&status); // aspetta terminazione del figlio, per evitare Zombie process.
    }
    else
    {
        // chiusera pipe perché non è stato possibile effettuare la fork.
        close(fd[0]);
        close(fd[1]);
        printf("Erorre nella creazione della pipe\n");
        exit(-1);
    }
    // chiusura pipe.
    close(fd[0]);
    close(fd[1]);
    return 0;
}