#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Controlla se una stringa contiene solo lettere
int justLetters(char stringa[])
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        // Uso il codice ASCII per controllare se è una lettera maiuscola o minuscola
        if (!((stringa[i] >= 'A' && stringa[i] <= 'Z') || (stringa[i] >= 'a' && stringa[i] <= 'z')))
        {
            return 0;
        }
    }
    return 1; // true
}

// Controlla la presenza di una lettera nella stringa
int verificaPresenza(char lettera, char stringa[])
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == lettera)
        {
            return 1;
        }
    }
    return 0;
}

// Restituisce una nuova stringa con i caratteri nelle posizioni pari
char* evenString(char string[])
{
    int len = strlen(string);
    char* evenStr = (char*)malloc((len / 2 + 1) * sizeof(char)); // Alloco spazio per la stringa
    int k = 0;

    for (int i = 0; i < len; i += 2)
    {
        evenStr[k++] = string[i];
    }
    evenStr[k] = '\0'; // Termino la stringa con il carattere null

    return evenStr;
}

int main(int argc, char** argv)
{
    char string1[100];
    char lettera;

    printf("Inserire stringa \n");
    scanf("%s", string1); // Lettura della stringa

    printf("Stringa inserita: %s \n", string1);

    // Verifico se la stringa contiene solo lettere
    if (!justLetters(string1))
    {
        printf("La stringa non contiene solo lettere \n");
    }
    else
    {
        printf("La stringa contiene solo lettere \n");
    }

    // Consumo il newline rimasto nel buffer dopo la lettura della stringa
    getchar();

    // Verifico la presenza di una lettera nella stringa
    printf("Digitare una lettera per verificarne la presenza: \n");
    scanf("%c", &lettera);

    if (verificaPresenza(lettera, string1))
    {
        printf("La lettera inserita è presente \n");
    }
    else
    {
        printf("La lettera inserita non è presente \n");
    }

    // Chiamo la funzione evenString
    char* evenStr = evenString(string1);
    printf("Stringa con i caratteri in posizione pari: %s\n", evenStr);

    free(evenStr); // Libero la memoria allocata

    return 0;
}
