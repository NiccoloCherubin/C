#include <stdio.h>
int Somma(int a, int b)
{
    return a+b;
}
int main(int argc, char *argv[])
{
    int a,b;
    printf("Inserisci numero 1 \n");
    scanf("%d", &a);
    printf("Inserisci numero 2 \n");
    scanf("%d", &b);
    printf("La somma è %d \n",Somma(a,b));
    return 0;
}