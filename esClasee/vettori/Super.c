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
int Riempi(int array[], int *p)
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
        *p++;
    }
    return *p;
}
void Menu(int scelta)
{
    printf("Premere 1 per mostrare contenuto array \n");
    printf("Premere 2 per Inserire elemento in coda \n");
    printf("Premere 3 per modificare un elemento, se presente \n");
    printf("Premere 4 per eliminare un elemento, se presente \n");
    printf("Premere 5 per ricercare un elemento \n");
    printf("Premere 6 per per inserire un elemento in una certa posizione \n");
    printf("Premere 7 per mostrare contenuto dell'array all'inverso \n");
    printf("Premere 8 per per mostrare il valore massimo nell'array \n");
    printf("Premere 0 per terminare\n");
}
int main(int argc, char *argv[])
{
    // mostra array prima del menù
    int array[SHRT_MAX];
    int n;
    int *p = &n;
    int scelta;
    n = Riempi(array, p);
    do
    {
        Menu(scelta);
        scanf("%d", &scelta);
        if (scelta == 0)
        {
            printf("Programma finito");
            break;
        }
        else
        {
            // fare switch
        }
    } while (1);

    return 0;
}