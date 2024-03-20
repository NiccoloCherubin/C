#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //controllo dati in input
    if (argc != 4)
    {
        fprintf(stderr, "Utilizzo: %s <nome> <cognome> <età>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Stampa i dati ricevuti
    printf("Dati dello studente:\n");
    printf("Nome: %s\n", argv[1]);
    printf("Cognome: %s\n", argv[2]);
    printf("Età: %s\n", argv[3]);

    return 0;
}
