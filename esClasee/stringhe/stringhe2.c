#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char nome[30]; // hanno \0 alla fine = delimitatore stringa
    int i = 0;
    printf("Inserisci il tuo nome \n");
    scanf("%s", nome); // no & perché puntatori
    printf("Il tuo nome è %s", nome);
    while (nome[i] != '\0') // per vedere quanto è lunga stringa
    {
        i++;
    }
    printf("La stringa è lunga %d \n", i);
    return 0;
}