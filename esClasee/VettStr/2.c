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
        for (int i = 0; i < strlen(argv[1]) - 1; i++)
        {
            if (argv[1][i] == argv[2][0])
            {
                argv[1][i] = argv[1][i + 1];
            }
        }
        argv[1][strlen(argv[1]-1)] = ' ';

        printf("\n %s", argv[1]);
    }
    return 0;
}