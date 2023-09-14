#include <stdio.h>

int main(int argc, char *argv[])
{

    int n, i;

    do
    {
        printf("Inserisci un numero maggiore o uguale ad 1: \n");
        scanf("%d", &n);
    } while (n <= 1);

    i = n;
    do
    {
        printf("%d\n", i);
        i = i - 1;
    } while (i > 0);

    return 0;
}