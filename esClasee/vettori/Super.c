// no printf in funzioni
// per modifcare N usa puntatori. 2-
// firme funzioni
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int Controllo(int a, int cont)
{
    do
    {
        printf("Inserisci elemento %d \n", cont + 1);
        scanf("%d", &a);
        if (a == -1)
        {
            break;
        }
    } while (a < 0);
}
int Riempi(int array[], int n)
{
    int temp; // variabile temporanea per non sporcare array
    for (int i = 0; i < SHRT_MAX; i++)
    {
        temp = Controllo(temp, i);
        if (temp == -1)
        {
            break;
        }
        else
        {
            array[i] = temp;
        }
        n++;
    }
    return n;
}
int main(int argc, char *argv[])
{
    // mostra array prima del menù
    int array[SHRT_MAX];
    int n;
    n = Riempi(array, n);
    return 0;
}