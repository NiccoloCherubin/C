#include <stdio.h>
int main(int argc, char *argv[])
{
    // compresi tra 30 e 50 e calcolare somma
    int limite1, limite2, n, somma, i = 0;
    const short min = 30, max = 50;
    while (i < 5)
    {
        printf("Inserire numero 1 \n");
        scanf("%d", &limite1);
        printf("Inserire numero 2 \n");
        scanf("%d", &limite2);
        if (limite1 <= max && limite2 <= max && limite1 >= min && limite2 >= min)
        {
            i++;
        }
        else
        {
            printf("\n I numeri devono esserre compresi tra %d e %d", &limite1, &limite2);
        }
    }

    return 0;
}