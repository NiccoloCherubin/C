//CLIENT
#include <stdio.h>       
#include <stdlib.h>      
#include <sys/socket.h>  
#include <sys/types.h>   
#include <netinet/in.h>  
#include <string.h>      
#include <errno.h>       
#include <ctype.h>       
#include <unistd.h>     

#define DIM 50
#define SERVERPORT 1313

int main(int argc,char** argv)
{   
    struct sockaddr_in servizio;
    
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); 
    servizio.sin_port=htons(SERVERPORT);       
    char str[DIM];     //Stringa da inviare
    char car;
    int socketfd;// identificatore della socket
    
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));    

    printf("Inserisci la stringa\n");
    scanf("%s",str);

    printf("Inserisci carattere da ricercare\n");
    scanf(" %c",&car); //ignora carattere lasciato dal precendetne scanf

    write(socketfd,str,sizeof(str));
    write(socketfd,&car,sizeof(char));

    close(socketfd);
    return 0;
}
