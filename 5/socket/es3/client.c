#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define DIM 1024
#define SERVERPORT 1313

int main(int argc, char **argv)
{
    struct sockaddr_in servizio;
    int socketfd;
    char str[DIM]; //dove verrà memorizzata la stringa da inviare al server

    int palindroma = 0; // variabile che dirà se è palindroma oppure no

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY); //sfrutta API del SO
    servizio.sin_port = htons(SERVERPORT);

    socketfd = socket(AF_INET,SOCK_STREAM, 0);

    //verifico se connessione è andata a buon fine
    if(connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) < 0)
    {
        exit(-1);
    }

    //faccio inserire stringa all'utente
    printf("Inserisci la stringa \n");
    scanf("%s", str);

    //scrivo al server stringa inserita dall'utente
    write(socketfd, str, sizeof(str)+1);

    //leggo dal server se la stringa è palindroma
    read(socketfd,&palindroma , sizeof(int));

    printf("palindromo = %d\n",palindroma);

    if(palindroma)
    {
        printf("La stringa inserita è palindroma\n");
    }
    else
    {
        printf("La stringa inserita non è palindroma\n");
    }

    //chiudo connessione 
    close(socketfd);

    return 0;
}