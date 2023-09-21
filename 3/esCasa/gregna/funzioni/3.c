#include <stdio.h>
#include <stdlib.h>
int Ricerca(int argc, char *argv[], int n)
{
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) == n)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int n;
    printf("Inserisci il numero da cercare nell'array: ");
    scanf("%d", &n);
    n = indice(argc, argv, n, 1);
    if (n == -1)
    {
        printf("Numero non trovato\n");
    }
    else
    {
        printf("Numero trovato in posizione %d\n", n);
    }
    return 0;
}