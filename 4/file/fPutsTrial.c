#include <stdio.h>
#include <stdlib.h>
void main()
{
    // scrivere in un file. Per linux tastiera e monitor sono due file (standard input e standard output e standard error)
    FILE *myFile; // puntatore ad una struttura

    // aprire file
    // fopen torna indirizzo memoria
    myFile = fopen("prova.txt", "a"); // nome, lettura o scrittura. Se non esiste lo crea. Si èuò dare path. Ogni volta che si apre cancella il contenuto. Con A(appende) concatena

    // controllare che sia successo
    if (myFile == NULL) // qualcosa andato storto
    {
        printf("File non aperto!");
        exit(1);
    }
    char vettNomi[20];
    printf("Ho aperto il file \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Inserire nome %d \n", i + 1);
        scanf("%s", vettNomi);
        fputs(vettNomi, myFile); // origine, destinazione
        fputc('\n', myFile); // aggiunge un carattere solo
    }
    // sempre chiudere il file
    fclose(myFile);
}