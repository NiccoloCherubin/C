#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int justLetters(char stringa[])
{
    for(int i = 0; i < strlen(stringa) - 1; i++)
    {
        //uso codice ascii
        if((int)stringa[i] < 65 || (int)stringa[i] > 90 || (int)stringa[i] < 97 || (int)stringa[i] > 112 )
        {
            return 0;
        }
    }
    return 1; //true
}

//controlla presenza di una lettera nella stringa
int verificaPresenza(char lettera, char stringa[])
{
    for(int i = 0; i < strlen(stringa) -1; i++)
    {
        if(stringa[i] == lettera)
        {
            return 1;
        }
    }
    return 0;
}

/*
 char* evenString(char string[])
{
    char evenString[100];
    int k = 0;

    for(int i = 0; i < strlen(string); i+=2)
    {
        evenString
    }

    return evenString;
}
*/

int main (int argc, char **argv)
{
    char string1[100];
    char lettera;


    printf("Inserire stringa \n");
    scanf("%s", string1);

    printf("stringa %s \n", string1);


    //verifico ci siano solo lettere
    if(!justLetters(string1))
    {
        printf("La stringa non contiene solo caratteri \n");        
    }
    else{
        printf("La stringa contiene solo caratteri \n");
    }
    
    printf("Digitare lettere per verificarne la presenza \n");
    scanf("%c", &lettera);


    if(verificaPresenza(lettera, string1))
    {
        printf("la lettera inserita è presente \n");
    }
    else{

        printf("la lettera inserita non è presente \n");
    }

    return 0;
}