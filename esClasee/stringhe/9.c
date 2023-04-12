#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char stringa1[100], stringa2[100], pari[50], dispari[50];
    int lettere = 1, voc[2], cons[2];
    voc[0] = voc[1] = cons[0] = cons[1] = 0;
    do
    {
        printf("Inserisci stringa \n");
        scanf(" %s", stringa1);
        for (int i = 0; i < strlen(stringa1) && lettere == 1; i++)
        {
            if (!isalpha(stringa1[i])) // verifica appartenenza valore all'alfabeto
            {
                printf("Inserisci solo caratteri dell'alfabeto. ");
                lettere = 0;
                break;
            }
            if (i % 2 == 0)
            {
                pari[i / 2] = stringa1[i];
            }
            else
            {
                dispari[(i - 1) / 2] = stringa1[i];
            }
            if (
                tolower(stringa1[i]) == 'a' || tolower(stringa1[i]) == 'e' || tolower(stringa1[i]) == 'i' || tolower(stringa1[i]) == 'o' || tolower(stringa1[i]) == 'u')
            {
                voc[0]++;
            }
            else
            {
                cons[0]++;
            }
        }
    } while (lettere == 0);
    printf("Inserisci la seconda stringa \n");
    scanf(" %s", stringa2);
    for (int i = 0; i < strlen(stringa2); i++)
    {
        if (isalnum(stringa2[i])) // guarda se è un valore alfanumerico
        {
            if (
                tolower(stringa2[i]) == 'a' || tolower(stringa2[i]) == 'e' || tolower(stringa2[i]) == 'i' || tolower(stringa2[i]) == 'o' || tolower(stringa2[i]) == 'u')
            {
                voc[1]++;
            }
            else
            {
                cons[1]++;
            }
        }
    }
    printf("Nella prima stringa le lettere ad indice pari sono: %s, mentre quelle ad indice dispari sono: %s\n", pari, dispari);
    if (strlen(stringa1) == strlen(stringa2))
    {
        printf("Le due stringe hanno la stezza lunghezza\n");
    }
    else if (strlen(stringa1) > strlen(stringa2))
    {
        printf("La prima stringa è più lunga\n");
    }
    else
    {
        printf("La seconda stringa è più lunga\n");
    }
    if (voc[0] != voc[1])
    {
        if (voc[0] > voc[1])
        {
            printf("La prima stringa ha più vocali\n");
        }
        else
        {
            printf("La seconda stringa ha più vocali\n");
        }
    }
    else
    {
        printf("Le due hanno lo stesso numero di vocali \n");
    }   

    if (cons[0] == cons[1])
    {
        printf("Le due stringe hanno lo stesso numero di consonanti\n");
    }
    else if (cons[0] > cons[1])
    {
        printf("La prima stringa ha più consonanti\n");
    }
    else
    {
        printf("La seconda stringa ha più consonanti\n");
    }

    return 0;
}