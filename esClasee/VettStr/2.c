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
        for (int i = 0; i < argc - 1; i++) // - 1 per guardare solo la stringa
        {
            if (argv[2][i] == argv[3])
            {
                argv[2][i] = "";
            }
        }
        // stampo stringa finale
        printf("\n %s", stringa);
    }
    return 0;
}