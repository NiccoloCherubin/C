#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int p;     // permette di gestire padre e figlio.
int main() // nasce processo padre
{
    int status;
    // FORK
    // processo padre e figlio
    //  si visualizzano PID a vicenda
    //  p = valore tornato dalla fork
    //  p padre = PID figlio
    //  p nel figlio = 0

    // pc(program counter) segna indirizzo informazione successiva
    p = fork(); // padre genera figlio
    if (p == 0) // figlio
    {
        printf("\n1_SONO IL FIGLIO p=%d PID = %d PID padre = %d\n", p, getpid(), getppid());
        exit(25);
    }
    else // padre
    {
        
        printf("3_Attendo mio figlio %d %d \n",WEXITSTATUS(status), wait(&status));
        printf("\n 2_SONO IL PADRE  p=%d PID= %d PID padre = %d\n", p, getpid(), getppid());
        printf("4_Attendo mio figlio %d %d \n",WEXITSTATUS(status), wait(&status));
    }

    return 0;
}