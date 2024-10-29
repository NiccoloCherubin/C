#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define SERVERPORT 1314
#define DIM 50

// funzione che riempie l'array con numeri casuali
void fillArray(int *vett) {
  srand(time(NULL));
  for (int i = 0; i < DIM; i++) {
    vett[i] = rand() % 101; // valori casuali tra 0 e 100
  }
}

int main(int argc, char **argv) {
  struct sockaddr_in servizio;
  int socketfd, len = sizeof(servizio);
  int arr[DIM];
  int max, min;

  servizio.sin_port = htons(SERVERPORT);
  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);

  // Creazione del socket
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0) {
    perror("Errore nella creazione del socket \n");
    exit(-1);
  }

  // Connessione al server
  if (connect(socketfd, (struct sockaddr *)&servizio, len) < 0) {
    perror("Errore nella connessione \n");
    close(socketfd);
    exit(-1);
  }

  // Riempio l'array
  fillArray(arr);

  // Invio dell'array al server
  if (write(socketfd, arr, DIM * sizeof(int)) < 0) {
    perror("Errore nella scrittura dell'array al server \n");
    close(socketfd);
    exit(-1);
  }

  printf("Array inviato al server \n");

  // Ricevo il massimo dal server
  if (read(socketfd, &max, sizeof(max)) < 0) {
    perror("Errore lettura massimo dal server \n");
    close(socketfd);
    exit(-1);
  }

  // Ricevo il minimo dal server
  if (read(socketfd, &min, sizeof(min)) < 0) {
    perror("Errore lettura minimo dal server \n");
    close(socketfd);
    exit(-1);
  }

  printf("Massimo: %d \n", max);
  printf("Minimo: %d \n", min);

  // Chiudo la socket
  close(socketfd);

  return 0;
}
