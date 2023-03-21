#include <stdio.h>
int main(int argc, char *argv[])
{
    int n;
    int primo = 0; // come true e false
    do
    {
        printf("Inserisci un numero \n");
        scanf("%d", &n);
    } while (n <= 0);
    for (int i = 2; i < 10 && primo == 0; i++) // verifico tutti i numeri naturali senza contare 1
    {
        if (n % i == 0)
        {
            primo = 1;
        }
    }
    if (primo == 1)
    {
        printf("Il numero inserito non è un numero primo \n");
    }
    else
    {
        printf("Il numero inserito è un numero primo \n");
    }
    return 0;
}