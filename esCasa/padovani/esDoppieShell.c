#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{    
    int doppie = 0; // per contare quante volte è presente il carattere nella stringa
    if (argc != 2) // verifico quantità argomenti inseriti
    {
        printf("Errore argomenti");
    }
    else
    {
        for (int i = 0; i < argc ; i++)
        {
            if (argv[2][i] == argv[2][i + 1]) // verifico se ci sono doppie
            {
                doppie += 2; // conto numero di doppie
            }
        }
        // stampa del numero di doppie
        printf("Nella stringa %s, sono presenti delle doppie %d volte \n", argv[2], doppie);
    }
    return 0;
}