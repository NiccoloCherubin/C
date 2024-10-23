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

void ordinaStringa(char *str)
{
    int i, j, temp;
    for (i = 0; i < strlen(str)-1; i++) {
        // L'ultimo i elementi sono già ordinati
        for (j = 0; j < strlen(str)-i-1; j++) {
            // Scambia se l'elemento corrente è maggiore del successivo
            if (str[j] > str[j+1]) {
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client
    
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM];
    
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    
    if(bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio)) < 0)
    {
        perror("Errore nella bind \n");
        exit(-1);
    }
    // metto il server in ascolto
    listen(socketfd,10);
    // ciclo infinito
    while(1)
    {
        printf("\n\nServer in ascolto...");
        fflush(stdout);
        //server accetta la connessione
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        
        read(soa,str,sizeof(str));
        printf("Stringa ricevuta: %s\n",str);

        //ordino la stringa
        ordinaStringa(str);

        printf("Stringa ordinata inviata: %s \n", str);

        //mando la stringa al client
        write(soa, str, sizeof(str));

        close(soa);
    }
   return 0;   
}
