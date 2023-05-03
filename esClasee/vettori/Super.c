// no printf in funzioni
// per modifcare N usa puntatori. 2-
// firme funzioni
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int Riempi(int array[], int n)
{
    int temp;
    for (int i = 0; i < SHRT_MAX; i++)
    {
        printf("Inserisci elemento %d \n", i);
        scanf("%d", &temp);
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