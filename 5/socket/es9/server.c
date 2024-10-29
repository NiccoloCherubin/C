#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SERVERPORT 1314
#define DIM 50

// Funzione per ordinare l'array usando il Bubble Sort
void bubbleSort(int *vett, int dim) {
  int temp;
  for (int i = 0; i < dim - 1; i++) {
    for (int j = 0; j < dim - i - 1; j++) {
      if (vett[j] > vett[j + 1]) {
        // Scambio degli elementi
        temp = vett[j];
        vett[j] = vett[j + 1];
        vett[j + 1] = temp;
      }
    }
  }
}

int main(int argc, char **argv) {
  struct sockaddr_in servizio, addClient;
  int socketfd, soa, clientLen = sizeof(servizio);
  int arr[DIM];

  servizio.sin_family = AF_INET;
  servizio.sin_port = htons(SERVERPORT);
  servizio.sin_addr.s_addr = htonl(INADDR_ANY);

  socketfd = socket(AF_INET, SOCK_STREAM, 0); // file descriptor della socket

  if (socketfd < 0) { // controllo errore apertura socket
    perror("Errore nella creazione del socket \n");
    exit(-1);
  }

  if (bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) < 0) { // bind e controllo errore
    perror("Errore nella bind \n");
    exit(-1);
  }

  listen(socketfd, 10); // metto in ascolto fino a 10 client

  while (1) {
    printf("Server in ascolto...\n");

    // accetto connessione dal client
    soa = accept(socketfd, (struct sockaddr *)&addClient, &clientLen);
    if (soa < 0) {
      perror("Errore accettazione connessione\n");
      exit(-1);
    }

    // leggo array dal client
    if (read(soa, arr, sizeof(arr)) < 0) {
      perror("Errore lettura array dal client\n");
      exit(-1);
    }

    // ordino l'array in modo crescente con Bubble Sort
    bubbleSort(arr, DIM);

    // mando l'array ordinato al client
    if (write(soa, arr, sizeof(arr)) < 0) {
      perror("Errore scrittura array ordinato al client\n");
      exit(-1);
    }

    printf("Array ordinato inviato al client.\n");
    close(soa);
  }

  return 0;
}
