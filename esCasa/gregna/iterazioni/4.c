#include <stdio.h>
int main(int argc, char *argv[])
{
    int numero;
    int i = 0;
    do
    {
        printf("Inserisci numero\n");
        scanf("%d", &numero);
    } while (numero <= 1 );
    if (numero % 2 == 1)
    {
        numero--;
    }
    do
    {
        i += 2;
        numero = numero - 2;
        printf("%d \n", i);
    } while (numero != 0);

    return 0;
}