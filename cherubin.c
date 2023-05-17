// niccolò cherubin
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void Controllo(int *p)
{
    while (*p <= 0)
    {
        printf("Il numero deve essere maggiore di zero. Reinserire \n");
        scanf("%d", p);
    }
}
void FillArr(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        printf("Inserire %d elemento \n", i + 1);
        scanf("%d", &array[i]);
        Controllo(array + i); // passo l'indirizzo dell'elemento per modificare l'originale
    }
}
void PrintArr(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        printf("%d \n", array[i]);
    }
}
int Maggiore(int array[], int lunghezza)
{
    int max = array[0];
    for (int i = 0; i < lunghezza; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
int NumeroFrequente(int array[], int lunghezza)
{
    int temp = 0;
    int cont[lunghezza];
    // fixed
    for (int i = 0; i < lunghezza; i++)
    {
        cont[i] = 0;
    }
    // fixed
    for (int i = 0; i < lunghezza; i++)
    {
        temp = array[i];
        for (int j = 0; j < lunghezza; j++)
        {
            if (temp == array[j])
            {
                cont[i]++;
            }
        }
    }
    temp = Maggiore(cont, lunghezza); // fixed
    return temp;
}
int main(int argc, char *argv[])
{
    int lunghezza;
    printf("Quanti elementi vuoi inserire \n");
    scanf("%d", &lunghezza);
    Controllo(&lunghezza);
    int array[lunghezza];
    FillArr(array, lunghezza); // funzione che riempe l'array
    printf("Ecco il contenuto dell'array \n");
    PrintArr(array, lunghezza);
    printf("Il numero più frequente nell'array è %d \n", NumeroFrequente(array, lunghezza));
    return 0;
}