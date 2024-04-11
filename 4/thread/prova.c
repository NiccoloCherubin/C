#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// trhead POSIX (standard in tutti i sistemi UNIX).
// Queste funzioni devono avere certa firma

void *stampaGiorno(void *par) // primo thread
{
    printf("%s\n", (char*)par);
    return (void*)0;
}
void *stampaSera(void *par) // secondo thread
{
    printf("%s\n", (char*)par);
    return (void*)0;
}
void *stampaNotte(void *par) // terzo thread
{
    printf("%s\n", (char*)par);
    return (void*)0;
}

int main()
{
    pthread_t threadGiorno;
    pthread_t threadSera;
    pthread_t threadNotte;

    char* msg1 = "buongiorno";
    char* msg2 = "buonaSera";
    char* msg3 = "buonaNotte";
    // indirizzo, valori di default per spostare gestione thread, inidirizzo istruzioni con funzione, qualcosa da passare alle funzioni
    pthread_create(&threadGiorno, NULL, &stampaGiorno, msg1);
    pthread_create(&threadSera, NULL, &stampaSera, msg2);
    pthread_create(&threadNotte, NULL, &stampaNotte, msg3);

    printf("ciao \n");

    //prima di tornare deve aspettare che le altre parti finiscano
    pthread_join(threadGiorno,NULL);
    pthread_join(threadSera,NULL);
    pthread_join(threadNotte,NULL);

    return 0;
}