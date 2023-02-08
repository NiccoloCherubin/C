#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char nome[30]; // hanno /0 alla fine
    int i;
    printf("Inserisci il tuo nome \n");
    scanf("%s", nome); //no & perché puntatori
    printf("Il tuo nome è %s", nome);
    return 0;
}