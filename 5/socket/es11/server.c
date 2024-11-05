#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SERVER_PORT 1314
#define DIM 100

int *evenOddFun(int *arr) {
  int *evenOdd = malloc(sizeof(int) * 2);
  evenOdd[0] = 0; // even
  evenOdd[1] = 0; // odd

  for (int i = 0; i < DIM; i++) {
    if (arr[i] % 2 == 0) {
      evenOdd[0]++;
    } else {
      evenOdd[1]++;
    }
  }
  
  return evenOdd;
}

int main(int argc, char **argv) {
  struct sockaddr_in servizio, addCLient;
  int socketfd, soa, size = sizeof(addCLient);
  int arr[100];
  int *evenOdd = malloc(sizeof(int) * 2);

  servizio.sin_addr.s_addr = htonl(INADDR_ANY);
  servizio.sin_port = htons(SERVER_PORT);
  servizio.sin_family = AF_INET;

  socketfd = socket(AF_INET, SOCK_STREAM, 0);

  if (socketfd < 0) {
    perror("Errore nella creazione del socket \n");
    exit(-1);
  }

  if (bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) < 0) {
    perror("Errore nella bind \n");
    exit(-1);
  }

  listen(socketfd, 10);

  while (1) {

    printf("Server in ascolto... \n");

    soa = accept(socketfd, (struct sockaddr *)&addCLient, &size);

    if (soa < 0) {
      perror("Errore nella connessione con il client \n");
      exit(-1);
    }

    if (read(soa, arr, sizeof(int) * DIM) < 0) {
      perror("Errore nella lettura dell'array dal client \n");
      exit(-1);
    }

    evenOdd = evenOddFun(arr);

    if (write(soa, evenOdd, sizeof(int) * 2) < 0) {
      perror("Errore nella scrittura dell'array sul client \n");
      exit(-1);
    }

    printf("Pari e dispari inviati al client \n");

    close(soa);
  }

  free(evenOdd);
}