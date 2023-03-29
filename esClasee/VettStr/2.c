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
        char supporto[50];
        int cont = 0;
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