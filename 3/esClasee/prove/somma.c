// Scrivere un programma in C, che dopo aver richiesto all'utente due numeri ne calcola la somma e media
#include <stdio.h>
void main()
{
    float num, somma = 0 , media;
    int n, i = 1; // contatori
    do
    {
        printf("Quanti numeri vuoi inserire ?\n");
        scanf("%d", &n);
    } while (n <= 0);

    do
    {
        printf("Inserire %d° numero \n", i); // per vedere che numero bisogna mettere
        scanf("%f", &num);
        somma = somma + num;
        i++;
        n--;
    } while (n != 0);
    media = somma / (i-1);
    printf("\n La somma risulta %.2f", somma);
    printf("\n La media risulta %.2f", media); // invece della variabile si scriveva direttamente nel printf
}