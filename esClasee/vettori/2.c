// inserimento vettore e visualizzazione elementi + somma e media
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int maxP, minP = __INT_MAX__, maxD, minD = __INT_MAX__, v[100], n;
    int posMaxP, posMaxD,posMinD,posMinP;
    do
    {
        printf("Quanti elementi vuoi inserire \n");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    for (int i = 0; i < n; i++)
    {
        printf("Inserisci IL numero %d \n", (i + 1));
        scanf("%d", &v[i]);
        if (v[i] % 2 == 0)
        {
            if (v[i] < minP)
            {
                minP = v[i];
                posMinP = i;
            }
            else
            {
                maxP = v[i];
                posMaxP = i;
            }
        }
        else
        {
            if (v[i] < minD)
            {
                minD = v[i];
                posMinD = i;
            }
            else
            {
                maxD = v[i];
                posMaxD = i;
            }
        }
    }
    printf("Il numero pari minimo è %d  e si trova alla posizione %d\n", minP, posMinP);
    printf("Il numero pari massimo è %d si trova alla posizione %d\n", maxP, posMaxP);
    printf("Il numero dispari minimo è %d si trova alla posizione %d\n ", minD, posMinD);
    printf("Il numero dispari massimo è %d si trova alla posizione %d\n", maxD, posMaxD);
    return 0;
}