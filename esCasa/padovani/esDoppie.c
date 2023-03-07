#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char stringa[20];
    int doppie = 0; // per contare quante volte è presente il carattere nella stringa
    // inserimento stringa
    printf("inserire stringa\n");
    scanf("%s", stringa);

    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (stringa[i] == stringa[i + 1]) // verifico se ci sono doppie
        {
            doppie += 2; // conto numero di doppie
        }
    }
    // stampa del numero di doppie
    printf("Il nella stringa %s, sono presenti delle doppie %d volte \n", stringa, doppie);
    return 0;
}