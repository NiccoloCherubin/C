#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// trhead POSIX (standard in tutti i sistemi UNIX).
// Queste funzioni devono avere certa firma

void *stampaGiorno(void *par) // primo thread
{
    printf("buongiorno \n");
}
void *stampaSera(void *par) // secondo thread
{
    printf("buonasera \n");
}
void *stampaNotte(void *par) // terzo thread
{
    printf("buonanotte \n");
}

int main()
{
    pthread_t threadGiorno;
    pthread_t threadSera;
    pthread_t threadNotte;

    // indirizzo, valori di default per spostare gestione thread, inidirizzo istruzioni con funzione, qualcosa da passare alle funzioni
    pthread_create(&threadGiorno, NULL, &stampaGiorno, NULL);
    pthread_create(&threadSera, NULL, &stampaSera, NULL);
    pthread_create(&threadNotte, NULL, &stampaNotte, NULL);

    printf("ciao \n");

    //prima di tornare deve aspettare che le altre parti finiscano
    pthread_join(threadGiorno,NULL);
    pthread_join(threadSera,NULL);
    pthread_join(threadNotte,NULL);
    
    return 0;
}