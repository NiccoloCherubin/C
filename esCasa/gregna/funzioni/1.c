#include <stdio.h>
int Somma(int a, int b)
{
    return a + b;
}
int Verifica(int valore)
{
    if (valore <= 0)
    {
        return -1;
    }
    else
    {
        return valore;
    }
}
int main(int argc, char *argv[])
{
    int a, b;
    do
    {
        printf("Inserisci numero 1 \n");
        scanf("%d", &a);
    } while (Verifica(a) == -1);
    do
    {
        printf("Inserisci numero 2 \n");
        scanf("%d", &b);
    } while (Verifica(b) == -1);
    printf("La somma è %d \n", Somma(a, b));
    return 0;
}