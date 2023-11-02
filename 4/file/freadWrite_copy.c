#include <stdio.h>
#include <stdlib.h>

#define BUFFER_DIM 4
int main(int argc, char *argv[])
{
    FILE *origine; // origine legge dati e destinazione scrive dati
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
    fclose(origine);
    return 0;
}