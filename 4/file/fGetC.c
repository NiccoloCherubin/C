#include <stdio.h>
#include <stdlib.h>
void main()
{

    FILE *myFile; // puntatore ad una struttura

    // aprire file
    // fopen torna indirizzo memoria
    myFile = fopen("prova.txt", "r"); // lettura

    // controllare che sia successo
    if (myFile == NULL) // qualcosa andato storto
    {
        printf("File non aperto!");
        exit(1);
    }
    char vettNomi[20];
    printf("Ho aperto il file \n");
    char c;
    do
    {
        c = fgetc(myFile); // prende primo carattere che trova
        putchar(c); // stampa a video carattere
    } while (c != EOF); // End Of File

    fclose(myFile);
}