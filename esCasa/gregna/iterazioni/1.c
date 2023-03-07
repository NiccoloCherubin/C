#include <stdio.h>
int main(int argc, char *argv[])
{
    int numero;
    do
    {
        printf("Inserisci numero\n");
        scanf("%d", &numero);
    } while (numero < 0);
    numero++;
    printf("Il numero successivo è %d", numero);
    return 0;
}