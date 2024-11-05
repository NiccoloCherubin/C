#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define SERVER_PORT 1314
#define DIM 100

// funzione per popolare un array
void fillArr(int *arr) {
  srand(time(NULL));

  for (int i = 0; i < DIM; i++) {
    arr[i] = rand() % 101;
  }
}

int main(int argc, char **argv) {
  struct sockaddr_in servizio;
  int socketfd;
  int evenOdd[2];

  int arr[DIM];

  servizio.sin_family = AF_INET;
  servizio.sin_port = htons(SERVER_PORT);
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);

  socketfd = socket(AF_INET, SOCK_STREAM, 0);

  if (socketfd < 0) {
    perror("Errore nella creazione della socket \n");
    exit(-1);
  }

  if (connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) < 0) {
    perror("Errore nella connessione con il server \n");
    exit(-1);
  }

  fillArr(arr);

  if (write(socketfd, arr, sizeof(int) * DIM) < 0) {
    perror("Errore nell'invio dell'array al server \n");
    exit(-1);
  }

  printf("Array inviato al server \n");

  if (read(socketfd, evenOdd, sizeof(int) * 2) < 0) {
    perror("Errore nella lettura dei numeri pari dal server \n");
    exit(-1);
  }

  close(socketfd);

  printf("I numeri pari all'interno dell'array sono %d \n", evenOdd[0]);
  printf("I numeri dispari all'interno dell'array sono %d \n", evenOdd[1]);
}