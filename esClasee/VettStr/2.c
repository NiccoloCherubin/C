#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore argomenti");
    }
    else
    {
        char stringa[50] = argv[2];
        char carattere = argv[3];
        for (int i = 0; i < argc - 1; i++) // - 1 per guardare solo la stringa
        {
            if (stringa[i] == carattere)
            {
                stringa[i] = "";
            }
        }
        // stampo stringa finale
        printf("\n %s", stringa);
    }
    return 0;
}