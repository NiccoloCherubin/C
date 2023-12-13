#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int p, somma, n1 = 1, n2 = 2, n3 = 3;
    int status;
    do
    {

        printf("inserisci numero uno \n");
        scanf("%d", &n1);
    } while (n1 < 0);

    do
    {
        printf("inserisci numero due \n");
        scanf("%d", &n2);
    } while (n2 < 0);
    do
    {
        printf("inserisci numero tre \n");
        scanf("%d", &n3);
    } while (n3 < 0);

    p = fork();
    if (p < 0)
    {
        printf("Ci sono stati degli errroi");
        exit(1);
    }
    if (p != 0) // padre
    {
        wait(&status); //padre aspetta il figlio
        printf("somma = %d \n", WEXITSTATUS(status)); //stampa il valore passato dal figlio
    }
    else // figlio
    {
        somma = n1 + n2 + n3;
        exit(somma); // passa al padre il valore
    }
    return 0;
}