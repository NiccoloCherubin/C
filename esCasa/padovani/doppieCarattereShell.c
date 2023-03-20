#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int volte = 0; // per contare quante volte è presente il carattere nella stringa
    if (argc != 2) // verifico quantità argomenti inseriti
    {
        printf("Errore argomenti");
    }
    else
    {
        for (int i = 0; i < argc; i++)
        {
            if (argv[2][i] == argv[3]) // verifico se carattere presente
            {
                volte += 1; // conto numero di volte
            }
        }
        // stampa del numero di doppie
        printf("Nella stringa %s, il carattere %s  è presente %d volte \n", argv[2], argv[3], volte);
    }
    return 0;
}