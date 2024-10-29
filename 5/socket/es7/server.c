#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SERVERPORT 1314
#define DIM 50

// FUNZIONE CHE CALCOLA LA SOMMA SOLO DEI NUMERI DISPARI

int sumOdd(int *vett, int *countOdd) {
  int somma = 0;
  *countOdd = 0;

  for (int i = 0; i < DIM; i++) {
    if (vett[i] % 2 != 0) { // verifica se il numero è dispari
      somma += vett[i];
      (*countOdd)++; // incrementa il contatore dei numeri dispari
    }
  }

  return somma;
}

int main(int argc, char **argv) {
  struct sockaddr_in servizio, addClient;
  int socketfd, soa, clientLen = sizeof(servizio);
  int arr[DIM];
  int somma, countOdd;
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

    // accetto connessione dal client
    soa = accept(socketfd, (struct sockaddr *)&addClient, &clientLen);

    // leggo array dal client
    if(read(soa, arr, sizeof(arr)) < 0) {
        perror("Errore lettura array dal client \n");
        exit(-1);
    }

    // calcolo somma e media dei numeri dispari
    somma = sumOdd(arr, &countOdd);
    media = countOdd > 0 ? (float)somma / countOdd : 0; // evita divisione per zero

    printf("Media dei numeri dispari: %f\n", media);
    printf("Somma dei numeri dispari: %d\n", somma);

    // mando al client i risultati
    if(write(soa, &somma, sizeof(somma)) < 0) {
        perror("Errore scrittura somma al client \n");
        exit(-1);
    }
    if(write(soa, &media, sizeof(media)) < 0) {
        perror("Errore scrittura media al client \n");
        exit(-1);
    }
  }
  return 0;
}
