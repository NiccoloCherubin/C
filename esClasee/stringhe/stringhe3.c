#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i = 0, cons = 0, voc = 0, lung = i, num = 0;
    char str[20]; // dichiarazione stringa
    printf("Inserire stringa \n");
    scanf("%s", str); // input della stringa
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
            if (str[i] != 'a' || str[i] != 'e' || str[i] != 'i' || str[i] != 'o' || str[i] != 'u' && (str[i] > 'a' && str[i] < 'z')) // per codice ascii (compreso tra lettere)
            {
                cons++;
            }
            else
            {
                num++;
            }
        }
        
        printf("Le vocali sono %d \n", voc);
        printf("Le consonanti sono %d \n", cons);
        printf("I numeri sono %d \n", num);
        return 0;
    }
    }