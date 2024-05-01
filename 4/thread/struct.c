#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct
{
    char nome[20];
    char classe[20];
    char cognome[20];
    float media;
} Studente;
void *stampaDatiInseriti(void *par)
{
    Studente s = *((Studente *)par);
    printf("nome:%s\n", s.nome);
    printf("cognome:%s\n", s.cognome);
    printf("classe:%s\n", s.classe);
    printf("media:%.2f\n", s.media);

    pthread_exit(NULL);
}
void *StampaDatiFile(void *par)
{
    Studente *s = (Studente *)par;
    FILE *file = fopen("dati_studente.txt", "w");

    // controllo errore apertura file
    if (file == NULL)
    {
        printf("Errore apertura file\n");
        exit(-1);
    }

    //stampa su file
    fprintf(file, "nome:%s\n", s->nome);
    fprintf(file, "cognome:%s\n", s->cognome);
    fprintf(file, "classe:%s\n", s->classe);
    fprintf(file, "media:%.2f\n", s->media);

    pthread_exit(NULL);
}
int main()
{

    pthread_t StampaDati;
    pthread_t StampaFile;

    Studente studente;

    // inserimento dati
    printf("Inserire nome studente \n");
    scanf("%s", studente.nome);
    printf("Inserire cognome studente \n");
    scanf("%s", studente.cognome);
    printf("Inserire classe studente \n");
    scanf("%s", studente.classe);
    printf("Inserire media studente \n");
    scanf("%f", &studente.media);

    // eseguo treahd
    pthread_create(&StampaDati, NULL, &stampaDatiInseriti, (void *)&studente);
    pthread_create(&StampaFile, NULL, &StampaDatiFile, (void *)&studente);

    // aspetto esecuzione thread
    pthread_join(StampaDati, NULL);
    pthread_join(StampaFile, NULL);

    // termine programma
    return 0;
}