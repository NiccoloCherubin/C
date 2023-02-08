#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char nome[30]; // hanno /0 alla fine
    printf("Inserisci nome \n");
    scanf ("%s", &nome);
    printf("Il tuo nome è %s", nome);
    return 0;
}