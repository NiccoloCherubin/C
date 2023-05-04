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
void StampaArr(int *arr, int n)

{
    printf("Elementi array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", *arr + i);
    }
}
void InsertCoda(int *arr, int numero, int dim)
{
    *(arr + dim) = numero;
}
int Ricerca(int *arr, int *ricercato, int dim)
{
    int pos = -1;
    for (int i = 0; i < dim; i++)
    {
        if (*(arr + i) == *ricercato)
        {
            pos = i;
        }
    }
    return pos;
}
void CambioElemento(int *arr, int posizione, int *numero)
{
    *(arr + posizione) = *numero;
}
void Elimination(int *arr, int posizione, int *dim)
{
    for (int i = posizione; i < *(dim - 1); i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    *dim--;
}
int main(int argc, char *argv[])
{
    // mostra array prima del menù
    int posizione;
    int ricercato;
    int array[SHRT_MAX];
    int n;
    int *p = &n;
    int scelta, numero;
    n = Riempi(array, n);
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
            // verifica della scelta fatta dall'utente
            switch (scelta)
            {
            case 1:
                StampaArr(array, n);
                break;
            case 2:
                printf("Inserire numero da mettere in coda \n");
                numero = scanf("%d", &numero);
                InsertCoda(array, numero, n);
                n++;
                break;
            case 3:
                printf("Inserire numero da cambiare \n");
                ricercato = scanf("%d", &ricercato);
                posizione = Ricerca(array, &ricercato, n);
                printf("%d\n", posizione);
                if (posizione != -1)
                {
                    printf("Inserire numero con cui sostituire il precedente \n");
                    numero = scanf("%d", &numero);
                    CambioElemento(array, posizione, &numero);
                    printf("Cambiamento avvenuto con successo \n");
                }
                else
                {
                    printf("Il numero inserito non è presente nell'array \n");
                }
                break;
            case 4:
                printf("Inserire numero da eliminare \n");
                ricercato = scanf("%d", &ricercato);
                posizione = Ricerca(array, &ricercato, n);
                if (posizione != -1)
                {
                    Elimination(array, posizione, &n);
                    printf("Elemento eliminato con successo \n");
                }
                else
                {
                    printf("Elemento non presente \n");
                }
                break;
            case 5:
                printf("Inserire numero da cercare \n");
                ricercato = scanf("%d", &ricercato);
                posizione = Ricerca(array, &ricercato, n);
                if (posizione != -1)
                {
                    printf("Elemento presente \n");
                }
                else
                {
                    printf("Elemento non presente \n");
                }
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            }
        }
    } while (1);

    return 0;
}