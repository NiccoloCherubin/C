#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char stringa[20];
    char carattere; // per inserire carattere
    int volte = 0;  // per contare quante volte è presente il carattere nella stringa
    // inserimento stringa
    printf("inserire stringa\n");
    scanf("%s", stringa);
    printf("inserire carattere\n");
    scanf("%c", &carattere);
    scanf("%c", &carattere);    
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere) // verifico se carattere se è presente
        {
            volte += 1; // conto numero di volte
        }
    }
    // stampa del numero di volte
    printf("Nella stringa %s, il carattere %c è presente %d volte \n", stringa, carattere, volte);
    return 0;
}