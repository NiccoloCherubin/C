#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// Definizione della struttura per lo studente
typedef struct
{
    char nome[50];
    char cognome[50];
    char eta[2];
} Studente;

int main()
{
    // Dati dello studente
    Studente studente;

    // Input dei dati dello studente dall'utente
    printf("Inserisci il nome dello studente:\n");
    scanf("%s", studente.nome);
    printf("Inserisci il cognome dello studente:\n");
    scanf("%s", studente.cognome);
    printf("Inserisci l'età dello studente:\n");
    scanf("%s", studente.eta);

    
    int pid = fork();

    if (pid < 0)
    {
        printf("fork");
        exit(-1);
    }

    if (pid == 0)  // Processo figlio
    {        
        execl("./p2", "p2", studente.nome, studente.cognome,studente.eta, NULL);

        printf("Errore execl"); // In caso di errore nell'esecuzione di execl
        exit(-1);
    }
    else // Processo padre (P1)
    { 
        // Aspetta il termine del processo P2
        wait(NULL);

        printf("Processo P2 completato\n");
    }

    return 0;
}
