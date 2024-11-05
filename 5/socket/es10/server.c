#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define SERVER_PORT 1314
#define DIM 50

char * longestString(char *str1, char* str2)
{
    char *risposta = malloc(sizeof(char)*DIM);

    if (strlen(str1) > strlen(str2))
    {
        risposta = str1;
    }
    else if (strlen(str1) < strlen(str2)) {

    risposta = str2;
    }
    else{
        risposta = "le stringhe sono lunghe uguali";
    }

    return risposta;
}

int main(int argc, char **argv)
{
    struct sockaddr_in servizio,addCLient;
    int socketfd,soa,size = sizeof(addCLient);
    char str1[DIM];
    char str2[DIM];
    char *risposta = malloc(sizeof(char)*DIM);

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVER_PORT);

    //creo il socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if(socketfd < 0)
    {
        perror("Errore nella creazione del socket \n");
        exit(-1);
    }

    //faccio la bind e ne verifico la riuscita
    if(bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)))
    {
        perror("Errore nella bind \n");
        exit(-1);
    }

    //metto il server in ascolto con un massimo di 10 client
    listen(socketfd, 10);

    while (1) {

        printf("Server in ascolto... \n");

        //accetto la connessione
        soa = accept(socketfd, (struct sockaddr*)&addCLient, &size);

        //verifco la riuscita della connessione
        if(soa < 0)
        {
            perror("Errore nella connessione con il client \n");
            exit(-1);
        }  

        //leggo le stringhe inviate dal client e ne verifico la riuscita
        if(read(soa, str1, DIM) < 0)
        {
            perror("Errore nella lettura della stringa 1 dal client \n");
        }
        if(read(soa, str2, DIM) < 0)
        {
            perror("Errore nella lettura della stringa 2 dal client \n");
        }

        //verifico quale stringa è la più lunga
        risposta = longestString(str1, str2);

        //scrivo al server la risposta
        if(write(soa, risposta, DIM) < 0)
        {
            perror("Errore nell'invio della risposta al client \n");
            exit(-1);
        }

        printf("Stringa risposta inviata al client \n");

        //chiudo la connessione col client
        close(soa);
    }

    free(risposta);

    return 0;
}