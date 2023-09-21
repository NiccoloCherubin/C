#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("argc: %d \n", argc);
    printf("Parametri argv \n");
    for (int i = 1; i < argc; i++)
    {
        printf("%d. %s \n", i,argv[i]);
    }
}