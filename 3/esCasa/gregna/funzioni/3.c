#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
<<<<<<< HEAD
int indice(int argc, char *argv[], int n, int start)
=======
int Ricerca(int argc, char *argv[], int n, int start)
>>>>>>> 55f13cd7196c85e5e1243e51ae29969d2401b2bd
=======
int Ricerca(int argc, char *argv[], int n)
>>>>>>> 1486783a6b5c477a66698a955cdd7c96c4cf090f
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
<<<<<<< HEAD
    int n;
    printf("Inserisci il numero da cercare nell'array: ");
    scanf("%d", &n);
    n = indice(argc, argv, n, 1);
    if (n == -1)
=======
    int numero;
    printf("Inserisci il numero da cercare nell'array: ");
    scanf("%d", &numero);
    numero = Ricerca(argc, argv, numero);
    if (numero == -1)
>>>>>>> 55f13cd7196c85e5e1243e51ae29969d2401b2bd
    {
        printf("Numero non trovato\n");
    }
    else
    {
<<<<<<< HEAD
        printf("Numero trovato in posizione %d\n", n);
=======
        printf("Numero alla posizione %d\n", numero);
>>>>>>> 55f13cd7196c85e5e1243e51ae29969d2401b2bd
    }
    return 0;
}