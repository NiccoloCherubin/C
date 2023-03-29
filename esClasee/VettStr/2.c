#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore argomenti \n");
    }
    else
    {
        char supporto[50]; // stringa di supporto
        int cont = 0; // contatore perla stringa di supporto    
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (argv[1][i] != argv[2][0])
            {
                supporto[cont] = argv[1][i];
                cont++;
            }
        }        
            printf("%s", supporto);            
    }
    return 0;
}