#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char autore[20];
    double prezzo;
    char titolo[20];
} biblioteca;
void popola(biblioteca *libro, int i)
{
    printf("Inserire autore del libro %d \n", i + 1);
    scanf("%s", libro->autore); // valore puntato da puntatori
    printf("Inserire titolo del libro %d\n", i + 1);
    scanf("%s", libro->titolo); // valore puntato da puntatori
    printf("Inserire prezzo del libro %d \n", i + 1);
    scanf("%lf", &libro->prezzo); // valore puntato da puntatori
}
void stampa(biblioteca *libri, int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        printf("Libro %d:\n", i + 1);
        printf("Autore: %s\n", libri[i].autore);
        printf("Titolo: %s\n", libri[i].titolo);
        printf("Prezzo: %lf\n", libri[i].prezzo);
    }
}
void sconto(biblioteca *libri, int lunghezza, int scontoPercentuale)
{
    for (int i = 0; i < lunghezza; i++)
    {
        libri[i].prezzo = libri[i].prezzo - (libri[i].prezzo * scontoPercentuale / 100);
    }
}
int main(int argc, char *argv[])
{

    const int lunghezza = 2;
    biblioteca libri[lunghezza];
    int scontoPercentuale;
    for (int i = 0; i < lunghezza; i++)
    {
        popola(&libri[i], i);
    }
    printf("PRIMA DELLO SCONTO");
    stampa(libri, lunghezza);
    printf("Inserisci lo sconto percentuale: ");
    scanf("%d", &scontoPercentuale);

    sconto(libri, lunghezza, scontoPercentuale);

    printf("Libri DOPO lo sconto:\n");
    stampa(libri, lunghezza);

    return 0;
}