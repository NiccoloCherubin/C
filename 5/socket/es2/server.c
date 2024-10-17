#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

//funzione che verifchi che il carattere sia una vocale
int isVawel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

//funzione che conta le consonanti e le vocali di una stringa
int* countConsonantandVowels(char *str)
{
    int *cont = malloc(sizeof(int) * 2); //creo il contatore e gli alloco spazio in memoria

    for(int i = 0; i < strlen(str); i++)
    {
        //verifico che non sia una vocale e che sia un carattere
        if(!isVawel(str[i]) && isalpha(str[i]))
        {
            cont[0]++; //conta le consonanti
        }
        else if(isalpha(str[i]))
        {
            cont[1]++; //conta vocali
        }
    }

    return cont;

}



int main()
{
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM];
    int *cont = malloc(sizeof(int)*2); //array con numero di vocali e consonanti
    // definizione dei dati del socket 
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    // impostazione del transport endpoint del server
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    // leghiamo l'indirizzo al transport endpoint
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    // poniamo il server in ascolto delle richieste dei client 
    listen(socketfd,10);// può attendere fino a 10 client
    // ciclo infinito
    for (; ;)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        //legge dal client
        read(soa,str,sizeof(str));
        
        printf("Stringa ricevuta: %s\n",str);
        
        //conto le consonanti della stringa
        cont = countConsonantandVowels(str);
        
        printf("Numero di consonati: %d e di vocali: %d inviati\n",cont[0], cont[1]);
        
        write(soa, cont, sizeof(int)*2);
        
        close(soa);

     }
      
   return 0;
    
}