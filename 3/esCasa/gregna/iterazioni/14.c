#include <stdio.h>
int main(int argc, char *argv[])
{
    int n1, n2;
    int prodotto = 0; // per calcolare prodotto
    do
    {
        printf("Inserire un numero maggiore di 0 \n");
        scanf("%d", &n1);
    } while (n1 <= 0);
    do
    {
        printf("Inserire un numero maggiore di 0 \n");
        scanf("%d", &n2);
    } while (n2 <= 0);
    for (int i = 0; i < n2; i++)
    {
        prodotto += n1;
    }
    printf("Il prodotto è %d \n", prodotto);
    return 0;
}