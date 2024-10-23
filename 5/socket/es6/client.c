#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define SERVERPORT 1313
#define DIM 50

// funzione che riempie l'array con numeri casuali
void fillArray(int *vett) {

  srand(time(NULL));
  for (int i = 0; i < DIM; i++) {
    vett[i] = rand() % 101; // da 0 a 100
  }
}

int main(int argc, char ** argv)
{
    struct sockaddr_in servizio;
    int socketfd, len = sizeof(servizio);
    int arr[DIM];
    int somma;
    float media;

    servizio.sin_port = htons(SERVERPORT);
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if(connect(socketfd, (struct sockaddr *)&servizio, len) < 0)
    {
        perror("Errore nella connessione \n");
        exit(-1);
    }

    //riempio l'array
    fillArray(arr);

    //scrvio l'array al server
    if(write(socketfd, arr, DIM * sizeof(int)) < 0)
    {
        perror("Erroer nella scrittura dell'array al server \n");
        exit(-1);
    }

    printf("Inviato array al server \n");

    //leggo somma da server
    if(read(socketfd, &somma, sizeof(somma))<0)
    {
        perror("Errore lettura somma dal server \n");
        exit(-1);
    }

    //leggo media da server
    if(read(socketfd, &media, sizeof(media))<0)
    {
        perror("Errore lettura media dal server \n");
        exit(-1);
    }

    printf("Media :%f \n",media);
    printf("Somma: %d \n",somma);
    

    //chiudo la socket
    close(socketfd);

    return 0;
}