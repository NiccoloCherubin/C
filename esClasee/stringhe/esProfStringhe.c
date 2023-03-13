#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char stringa[20], carattere;
    int volte = 0; // per contare quante volte è presente il carattere nella stringa
    // inserimento stringa
    printf("inserire stringa\n");
    scanf("%s", stringa);    
    // inserimento carattere per verificare se è nella stringa
    printf("inserire carattere\n");
    scanf("%c", &carattere);
    scanf("%c", &carattere);
    // controllo nella stringa se è presente il carattere inserito dall'utente
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere)
        {
            volte++; // conto numero di volte
        }
    }
    // stampa del numero di volte
    printf("Il carattere %c nella stringa %s, è presente %d \n", carattere, stringa, volte);
    return 0;
}