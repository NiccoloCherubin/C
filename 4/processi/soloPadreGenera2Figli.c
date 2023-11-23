#include <stdio.h>
#include <unistd.h>

int main() {
    int pid1, pid2;

    // Creazione del primo figlio
    pid1 = fork();

    if (pid1 == -1) {
        // Errore nella creazione del processo figlio
        printf("Errore nella creazione del primo figlio");
        exit(1);
    } else if (pid1 == 0) {
        // Codice del primo figlio
        printf("Primo figlio - PID: %d, PID del padre: %d\n", getpid(), getppid());
        exit(1);
    } else {
        // Codice del processo padre
        // Creazione del secondo figlio
        pid2 = fork();

        if (pid2 == -1) {
            // Errore nella creazione del secondo figlio
            printf("Errore nella creazione del secondo figlio");
            exit(1);            
        } else if (pid2 == 0) {
            // Codice del secondo figlio
            printf("Secondo figlio - PID: %d, PID del padre: %d\n", getpid(), getppid());
            exit(1);
        } else {
            // Codice del processo padre
            printf("Processo padre - PID: %d, PID dei figli: %d, %d\n", getpid(), pid1, pid2);
        }
    }

    return 0;
}
