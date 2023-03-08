// inserimento vettore e visualizzazione elementi + somma e media
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i, n, v[100], somma = 0;
    float media;
    do
    {
        printf("Quanti elementi vuoi inserire \n");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    for (i = 0; i < n; i++)
    {
        printf("Inserisci un numero di posizione %d \n", (i + 1));
        scanf("%d", &v[i]);
        somma = somma + v[i];
    }
    printf("Il vettore inserito è il seguente: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", v[i]);
    }
    media = (float)somma/(float)n;
    printf("La media dei valori inseriti è \n %2.f", media);
    return 0;
}