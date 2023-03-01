#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i, n, v[100];
    do
    {
        printf("Quanti elementi vuoi inserire \n");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    for (i = 0; i < n; i++)
    {
        printf("Inserisci un numero di posizione %d \n", (i + 1));
        scanf("%d", &v[i]);
    }
    printf("Il vettore inserito è il seguente: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", v[i]);
    }
    return 0;
}