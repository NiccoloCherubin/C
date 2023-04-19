#include <stdio.h>
#include <stdlib.h>

int Ricerca(int argc, char *argv[], int n, int start)
{
    for (int i = start; i < argc; i++)
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
    int numero;
    printf("Inserisci il numero da cercare nell'array: ");
    scanf("%d", &numero);
    numero = Ricerca(argc, argv, numero, 1);
    if (numero == -1)
    {
        printf("Numero non trovato\n");
    }
    else
    {
        printf("Numero alla posizione %d\n", numero);
    }
    return 0;
}