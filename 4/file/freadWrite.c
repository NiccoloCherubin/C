#include <stdio.h>
#include <stdlib.h>

#define BUFFER_DIM 1024
int main(int argc, char *argv[])
{
    FILE *origine, *destinazione; // origine legge dati e destinazione scrive dati
    int n;
    unsigned char buffer[BUFFER_DIM];
    if (argc != 3)
    {
        printf("Inserire correttamente parametri d'ingressos");
        exit(1);
    }

    origine = fopen(argv[1], "r"); // lettura
    if (origine == NULL)
    {
        printf("Apertura file origine mal riuscita");
        exit(1);
    }
    destinazione = fopen(argv[2], "w"); // scrittura
    if (destinazione == NULL)
    {
        printf("Apertura file destinazione mal riuscita");
        exit(1);
    }
    while (!feof(origine)) // file end of file
    {
        n = fread(buffer, 1, BUFFER_DIM, origine); // mette nel buffer, 1 carattere alla volta, fino a BUFFER_DIM(dimensione buffer), da origine
        if (n > 0) // se n = 0 file finito
        {
            fwrite(buffer,1,n,destinazione); // da buffer, 1 alla volta, dimensione n ottenuta prima, su destinazione
        }
    }
    fclose(origine);
    fclose(destinazione);
    return 0;
}