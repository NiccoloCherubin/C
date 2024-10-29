#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define SERVERPORT 1314
#define DIM 50

// Funzione per riempire l'array con numeri casuali
void fillArray(int *vett) {
  srand(time(NULL));
  for (int i = 0; i < DIM; i++) {
    vett[i] = rand() % 101; // da 0 a 100
  }
}

int main(int argc, char **argv) {
  struct sockaddr_in servizio;
  int socketfd;
  int arr[DIM];

  servizio.sin_port = htons(SERVERPORT);
  servizio.sin_family = AF_INET;
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);

  socketfd = socket(AF_INET, SOCK_STREAM, 0);

  if (connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) < 0) {
    perror("Errore nella connessione\n");
    exit(-1);
  }

  // riempio l'array
  fillArray(arr);

  printf("Array inviato al server:\n");
  for (int i = 0; i < DIM; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // invio l'array al server
  if (write(socketfd, arr, sizeof(arr)) < 0) {
    perror("Errore scrittura array al server\n");
    exit(-1);
  }

  // ricevo l'array ordinato dal server
  if (read(socketfd, arr, sizeof(arr)) < 0) {
    perror("Errore lettura array ordinato dal server\n");
    exit(-1);
  }

  printf("Array ordinato ricevuto dal server:\n");
  for (int i = 0; i < DIM; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // chiudo la socket
  close(socketfd);
  return 0;
}
