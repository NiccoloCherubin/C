#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SERVER_PORT 1314
#define DIM 50

int main(int argc, char **argv)
{
    struct sockaddr_in servizio;
    int socketfd;
    char str1[DIM];
    char str2[DIM];
    char risposta[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_port = htons(SERVER_PORT);
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);

    //creo il socket
    socketfd = socket(AF_INET,SOCK_STREAM,0);

    //verifco se la creazione del socket sia riuscita
    if(socketfd < 0)
    {
        perror("Errore nella creazione del socket \n");
        exit(-1);
    }

    //faccio inserire le stringhe all'utente
    printf("Inserire stringa 1 \n");
    scanf("%s",str1);
    printf("Inserire stringa 2 \n");
    scanf("%s",str2);

    //creo la connessione con il server e verifico se è riuscita
    if(connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio)) < 0)
    {
        perror("Errore nella connessione con il server \n");
        exit(-1);
    }

    //mando al server le due stringhe e ne verifico la riuscita
    if(write(socketfd, str1, DIM) < 0)
    {
        perror("Errore nella scrittura della stringa 1 al server \n");
    }
    if(write(socketfd, str2, DIM) < 0)
    {
        perror("Errore nella scrittura della stringa 1 al server \n");
    }

    //leggo dal server la risposta e ne verifico la riuscita
    if(read(socketfd, risposta, DIM) < 0)
    {
        perror("Errore nella lettura della risposta dal server \n");
        exit(-1);
    }

    //stampo la risposta ricevuta dal server
    printf("La stringa più lunga è %s \n", risposta);


    //chiudo il socket
    close(socketfd);

    return 0;
}