// Dopo aver letto N numeri calcolare la somma e la media dei numeri maggiori di 5
#include <stdio.h>
void main()
{
    int n, i = 1, num, somma = 0, media;
    const int var = 5;
    do
    {
        printf("Quanti numeri vuoi inserire ?\n");
        scanf("%d", &n);
    } while (n <= 0); // verifico che numero non possa essere minore di 0

    do
    {
        printf("Inserire %d° numero \n", i); // per vedere che numero bisogna mettere
        scanf("%d", &num);
        if (num > var) // verifico se numero maggiore di var = 5
        {
            somma = somma + num;
            i++;
        }

        else
        {
            printf("\n Il numero è minore o uguale a 5 e non verrà considerato");
        }
        n--;
    } while (n != 0);
    media = somma / (i - 1);
    printf("\n La somma risulta %d", somma);
    printf("\n La media risulta %d", media);
}