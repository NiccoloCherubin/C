#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int pFuori; // permette di gestire padre e figlio.
int main()
{
    printf("P fuori dal MAIN");
    pFuori = fork();
    if (pFuori != 0)
    {
        //padre
        printf("\n Sono il padre. Il mio PID è:%d. Il PID di mio figlio è %d\n", getpid(), pFuori);
    }
    else
    {
        //figlio
        printf("\nSono il figlio. Il mio PID è %d. Il PID di mio padre %d\n", getpid(), getppid());
    }
    printf("\n=========================\n");
    printf("Dentro al main");
    int pDentro;
    pDentro = fork();
    if (pDentro != 0)
    {
        //padre
        printf("\n Sono il padre. Il mio PID è:%d. Il PID di mio figlio è %d\n", getpid(), pDentro);
    }
    else
    {
        //figlio
        printf("\nSono il figlio. Il mio PID è %d. Il PID di mio padre %d \n", getpid(), getppid());
    }
    return 0;
}