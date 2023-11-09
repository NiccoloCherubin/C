#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int p;     // permette di gestire padre e figlio.
int main() // nasce processo padre
{
    // FORK
    // processo padre e figlio
    //  si visualizzano PID a vicenda
    //  p = valore tornato dalla fork
    //  p padre = PID figlio
    //  p nel figlio = 0

    // pc(program counter) segna indirizzo informazione successiva
    p = fork(); // padre genera figlio
    if (p != 0) // quello che fa padre
    {
        printf("\nSONO IL PADRE  p=%d PID= %d PID padre = %d", p, getpid(), getppid());
    }
    else // figlio
    {
        printf("\nSONO IL FIGLIO p=%d PID = %d PID padre = %d\n", p, getpid(), getppid());
    }

    return 0;
}