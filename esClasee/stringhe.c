#include <string.h> // per utilizzare funzioni stringhe
#include <stdio.h>
int main(int argc, char *argv[])
{
    char carattere;
    printf("inserisci carattere \n");
    scanf("%c", &carattere);
    printf("Hai scritto %c \n", carattere);
   // printf("Inserisci carattere \n");
   // carattere = getchar();
    printf("Hai scritto %c \n", carattere);
   // putchar(carattere);
    printf("il codice ASCII del codice ascii inserito equivale a %d \n  ", carattere);
    return 0;
}