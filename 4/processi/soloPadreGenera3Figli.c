#include <stdio.h>
#include <unistd.h>

int main() {
    int pid_qui, pid_quo, pid_qua;

    // Creazione del processo figlio Qui
    pid_qui = fork();

    if (pid_qui == -1) {
        perror("Errore nella creazione del processo figlio Qui");
        return 1;
    } else if (pid_qui == 0) {
        // Codice del processo figlio Qui
        printf("Sono il figlio QUI, il mio PID = %d\n", getpid());
        return 0;
    } else {
        // Codice del processo padre
        // Creazione del processo figlio Quo
        pid_quo = fork();

        if (pid_quo == -1) {
            perror("Errore nella creazione del processo figlio Quo");
            return 1;
        } else if (pid_quo == 0) {
            // Codice del processo figlio Quo
            printf("Sono il figlio QUO, il mio PID = %d\n", getpid());
            return 0;
        } else {
            // Codice del processo padre
            // Creazione del processo figlio Qua
            pid_qua = fork();

            if (pid_qua == -1) {
                perror("Errore nella creazione del processo figlio Qua");
                return 1;
            } else if (pid_qua == 0) {
                // Codice del processo figlio Qua
                printf("Sono il figlio QUA, il mio PID = %d\n", getpid());
                return 0;
            } else {
                // Codice del processo padre
                printf("Sono il padre A, il mio PID = %d\n", getpid());
            }
        }
    }

    return 0;
}
