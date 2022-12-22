// calcolare somma dei numeri pari
#include <stdio.h>
void main()
{
    int n, i = 1, num, somma = 0;
    do
    {
        printf("Quanti numeri vuoi inserire ?\n");
        scanf("%d", &n);
    } while (n <= 0);

    do
    {
        printf("Inserire %d° numero \n", i); // per vedere che numero bisogna mettere
        scanf("%d", &num);
        if (num % 2 == 0) // verifico se numero pari o dispari
        {
            somma = somma + num;
        }

        else
        {
            printf("\n Il numero %d è dispari e non verrà considerato", num);
        }
        i++;
        n--;
    } while (n != 0);
    printf("\n La somma dei numeri pari risulta %d", somma);
}