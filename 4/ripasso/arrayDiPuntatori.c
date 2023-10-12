#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct // definisco struct
{
    char nome[20];
    char cognome[20];
    int media;
} Studente;
void stampa(Studente *studenti[], const int len)
{
    // stampa array
    for (int i = 0; i < len; i++)
    {
        printf("Nome : %s \n", (studenti[i]->nome));
        printf("Cognome : %s \n", (studenti[i]->cognome));
        printf("Media : %d \n", (studenti[i]->media));
    }
}
void popola(Studente *studenti[], int i)
{
    // popola array
    printf("Inserire nome dello studente %d \n", i + 1);
    scanf("%s", studenti[i]->nome); // valore puntato da puntatori
    printf("Inserire cognome dello studente %d\n", i + 1);
    scanf("%s", studenti[i]->cognome); // valore puntato da puntatori
    printf("Inserire media dello studente %d \n", i + 1);
    scanf("%d", &studenti[i]->media); // valore puntato da puntatori
}
int main(int argc, char *argv[])
{

    const int lunghezza = 3;
    Studente *studenti[lunghezza]; // creo array di puntatori
    for (int i = 0; i < lunghezza; i++)
    {
        studenti[i] = (Studente *)malloc(sizeof(Studente)); // alloco memoria
        popola(studenti, i);
    }
    stampa(studenti, lunghezza);
    //  libero memoria occupata
    for (int i = 0; i < lunghezza; i++)
    {
        free(studenti[i]);
    }

    return 0;
}
