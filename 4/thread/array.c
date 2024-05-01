#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define CERCARE 8;
int numeri[] = {8, 2, 3, 4, 5, 6, 7, 5, 8, 10, 11};

void *RicercaNumero(void *par)
{
    int *numero = (int *)par;
    for (int i = 0; i < 5; i++)
    {
        if (numero[i] == numeroDaCercare)
        {
            printf("Il numero %d è presente in %d\n", numeroDaCercare, i);
            exit(0);
        }
    }

    pthread_exit(NULL);
}
int main()
{

    pthread_t RicercaPrimaMeta;
    pthread_t RicercaSecondaMeta;

    pthread_create(&RicercaPrimaMeta, NULL, ricercaNumero, (void *)numeri);
    pthread_create(&RicercaSecondaMeta, NULL, ricercaNumero, (void *)numeri);

    pthread_join(RicercaPrimaMeta, NULL);
    pthread_join(RicercaSecondaMeta, NULL);

    return 0;
}