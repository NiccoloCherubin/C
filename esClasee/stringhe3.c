#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i = 0, cons = 0, voc = 0, lung = i;
    char stringa[20]; // dichiarazione stringa
    printf("Inserire stringa \n");
    scanf("%s", stringa); // input della stringa
    while (str[i] != '\0')
    {
        i++; // calcolo lunghezza stringa
    }
    lung = i;
    for (int i = 0; i < lung; i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            voc++;
        }
        else
        {
            cons++;
        }
        printf("Le vocali sono %d \n", voc);
        printf("Le consonanti sono %d \n", cons);
    }
    return 0;
}