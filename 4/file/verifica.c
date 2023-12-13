#include <stdio.h>
#include <stdlib.h>
#define BUFFER_DIM 1024
int main(int argc, char *argv[])
{
    // input: origine, destinazione
    if (argc != 3)
    {
        printf("Argomenti insufficienti");
        exit(1);
    }
    int n;
    FILE *origine, *destinazione;
    unsigned char buffer[BUFFER_DIM];
    origine = fopen(argv[1], "r");      // apro file in lettura
    destinazione = fopen(argv[2], "w"); // apro file in scrittura
    while (!feof(origine))
    {
        n = fread(buffer, 1, BUFFER_DIM, origine); // scrivo in buffer il contenuto in origine grande BUFFER_DIM
        if (n > 0)
        {
            fwrite(buffer,1,n, destinazione);
        }
    }
    fclose(origine);
    fclose(destinazione);
    printf("finito \n");
    return 0;
}