#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define DIM 1024
#define SERVERPORT 1313

int isNotPalindroma(char *str)
{
    for(int i = 0; i < strlen(str)/2;i++)
    {
        if(str[i] != str[strlen(str)-i-1])
        {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char ** argv)
{    
    struct sockaddr_in servizio, addClient;
    int socketfd, soa, clientLen = sizeof(servizio);
    char str[DIM];
    int palindromo = 0;

    //definizione dati del socket
    servizio.sin_family = AF_INET;
    servizio.sin_port = htons(SERVERPORT);
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);

    socketfd = socket(AF_INET,SOCK_STREAM,0);

    if(bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) < 0)
    {
        exit(-1);
    }

    //metto server in ascolto fino a 10 client
    listen(socketfd, 10); 

    while (1)
    {
        printf("Server in asoclto \n");

        //pulisco lo stream
        fflush(stdout);

        //accetto connessione dal client
        soa = accept(socketfd, (struct sockaddr*)&addClient, &clientLen);

        //leggo da client
        read(soa, str, sizeof(str));

        palindromo = isNotPalindroma(str);

        printf("palindromo = %d \n", palindromo);

        //scrivo al client
        write(soa, &palindromo, sizeof(int));
    }


    return 0;
}