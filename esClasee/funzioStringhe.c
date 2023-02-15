#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i = 0;
    char stringa1[20], stringa2[20];
    printf("inserire stringa 1 \n");
    scanf("%s", stringa1);
    i = strlen(stringa1); // string lengh = lunghezza strigna
    printf("La stringa è lunga %d \n", i);
    printf("inserire stringa 2 \n");
    scanf("%s", stringa2);
    i = strlen(stringa2); // string lengh = lunghezza strigna
    printf("La stringa è lunga %d \n", i);
    if (strcmp(stringa1, stringa2) == 0) // verifico se sono uguali con string compare
    {
        printf("le stringhe sono uguali");
    }
    else
    {
        printf("le stringhe sono diverse");
    }
    strcat(stringa1, stringa2);
    printf("La stringa concatenata è : %s", stringa1);
    return 0;
}