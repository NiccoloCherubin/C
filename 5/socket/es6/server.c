#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define SERVERPORT 1313
#define DIM 50

// FUNZIONE CHE CALCOLA LA SOMMA

int sum(int *vett) {
  int somma = 0;

  for (int i = 0; i < DIM; i++) {
    somma += vett[i];
  }

  return somma;
}

int main(int argc, char **argv) {
  struct sockaddr_in servizio, addClient;
  int socketfd, soa, clientLen = sizeof(servizio);
  int arr[DIM];
  int somma;
  float media;

  servizio.sin_family = AF_INET;
  servizio.sin_port = htons(SERVERPORT);
  servizio.sin_addr.s_addr = htons(INADDR_ANY);

  socketfd = socket(AF_INET, SOCK_STREAM, 0); // file descriptor della socket

  if (socketfd < 0) { // controllo errore apertura socket
    perror("Errore nella creazione del socket \n");
    exit(-1);
  }

  if (bind(socketfd, (struct sockaddr *)&servizio, clientLen) < 0) { // bind e controllo errore
    perror("Errore nella bind \n");
    exit(-1);
  }

  listen(socketfd, 10); // metto in ascolto fino a 10 client

  while (1) {

    printf("Server in ascolto \n");

    // pulisco lo stream

    // accetto connessione dal client
    soa = accept(socketfd, (struct sockaddr *)&addClient, &clientLen);

    // leggo array dal client
    if(read(socketfd, arr, sizeof(arr))<0)
    {
        perror("Errore lettura array dal client \n");
        exit(-1);
    }

    somma = sum(arr);
    media = (float)somma / DIM;

    printf("media : %f\n", media);
    printf("somma : %d\n", somma);

    // mando al client i risultati
    if(write(socketfd, &somma, sizeof(somma))<0)
    {
        perror("Errore scrittura somma al client \n");
        exit(-1);
    }
    if(write(socketfd, &media, sizeof(media)) < 0)
    {
        perror("Errore scrittura media al client \n");
        exit(-1);
    }
  }
  return 0;
}