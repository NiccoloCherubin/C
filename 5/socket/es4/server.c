//SERVER
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

int contaCarattere(char car, char* str)
{
    int cont = 0;

    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == car)
        {
            cont++;
        }
    }


    return cont;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client
    
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM];
    char car;
    
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    
    //creo connessione
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    
    //metto server in ascolto
    listen(socketfd,10);
    
    while(1)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
        //il server accetta la connessione
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);

        //legge dal client
        read(soa,str,sizeof(str));
        read(soa, &car, sizeof(char));

        printf("Stringa ricevuta: %s\n",str);
        printf("Carattere ricevuto: %c\n",car);

        printf("Il carattere è presente %d volte\n", contaCarattere(car, str));

        close(soa);
    }
   return 0;   
}
