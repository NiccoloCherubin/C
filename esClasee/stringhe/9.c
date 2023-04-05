#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char stringa[100];
    char stringaDispari[50] = "";
    char stringaPari[50] = "";
    int contPari = 0, contDispari = 0;
    short lettere = 0;
    do
    {
        printf("Inserisci una stringa\n");
        scanf("%s", stringa);
        for (int i = 0; i < strlen(stringa) && lettere == 0; i++)
        {
            if (stringa[i] < 'a' && stringa[i] > 'z')
            {
                lettere = 1;
            }
        }
    } while (lettere == 1);

    for (int i = 0; i < strlen(stringa); i++)
    {

        if (i % 2 == 0)
        {
            stringaPari[contPari] = stringa[i];
            contPari++;
        }
        else
        {
            stringaDispari[contDispari] = stringa[i];
            contDispari++;
        }
    }
    return 0;
}