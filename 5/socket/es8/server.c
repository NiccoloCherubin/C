#include <limits.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SERVERPORT 1314
#define DIM 50

// FUNZIONE CHE CALCOLA MASSIMO E MINIMO

int *maxAndMin(int *vett) {

  int *result =
      (int *)malloc(2 * sizeof(int)); // Array dinamico di due elementi
  if (result == NULL) {
    exit(-1); // Controllo per fallimento allocazione memoria
  }

  result[0] = INT_MIN; // Massimo
  result[1] = INT_MAX; // Minimo

  for (int i = 0; i < DIM; i++) {
    if (vett[i] > result[0]) {
      result[0] = vett[i];
    } else if (vett[i] < result[1]) {
      result[1] = vett[i];
    }
  }

  return result;
}

int main(int argc, char **argv) {
  struct sockaddr_in servizio, addClient;
  int socketfd, soa, clientLen = sizeof(servizio);
  int arr[DIM];
  int min, max;
  int *supp = malloc(sizeof(int) * 2);

  if(supp == NULL)
  {
    exit(-1);
  }

  servizio.sin_family = AF_INET;
  servizio.sin_port = htons(SERVERPORT);
  servizio.sin_addr.s_addr = htons(INADDR_ANY);

  socketfd = socket(AF_INET, SOCK_STREAM, 0); // file descriptor della socket

  if (socketfd < 0) { // controllo errore apertura socket
    perror("Errore nella creazione del socket \n");
    exit(-1);
  }

  if (bind(socketfd, (struct sockaddr *)&servizio, clientLen) <
      0) { // bind e controllo errore
    perror("Errore nella bind \n");
    exit(-1);
  }

  listen(socketfd, 10); // metto in ascolto fino a 10 client

  while (1) {

    printf("Server in ascolto \n");

    // pulisco lo stream

    // accetto connessione dal client
    if((soa = accept(socketfd, (struct sockaddr *)&addClient, &clientLen)) < 0)
    {
        exit(-1);
    }

    // leggo array dal client
    if (read(soa, arr, sizeof(arr)) < 0) {
      perror("Errore lettura array dal client \n");
      exit(-1);
    }

    supp = maxAndMin(arr);

    max = supp[0];
    min = supp[1];

    printf("max : %d\n", max);
    printf("min : %d\n", min);

    // mando al client i risultati
    if (write(soa, &max, sizeof(max)) < 0) {
      perror("Errore scrittura somma al client \n");
      exit(-1);
    }
    if (write(soa, &min, sizeof(min)) < 0) {
      perror("Errore scrittura media al client \n");
      exit(-1);
    }

    free(supp); // libero memoria allocata
  }
  return 0;
}