#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{    
    int contSpec = 0;
    int contAlf = 0;
    char stringa[100];
    char caratteriSpeciali[100];
    char ordineAlfabetico[100];
    printf("Inserire stringa \n");
    scanf("%s", stringa);
    
    for (int i = 0; i < strlen(stringa); i++)
    {
        if ((stringa[i] < 'a' || stringa[i] > 'z') && (stringa[i] < 'A' || stringa[i] > 'Z'))
        {
            caratteriSpeciali[contSpec] = stringa[i];
            contSpec++;
        }
        else if ((stringa[i] <= 'z' && stringa[i] >= 'a') || (stringa[i] <= 'Z' && stringa[i] <= 'A'))
        {
            ordineAlfabetico[contAlf] = stringa[i];
            contAlf++;
        }
    }

    printf("%s \n", caratteriSpeciali);
    printf("%s \n", ordineAlfabetico);
}