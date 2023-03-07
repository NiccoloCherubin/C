#include <stdio.h>
int main(int argc, char *argv[])
{
    int numero1, numero2;
    int i = 0;
    do
    {
        printf("Inserisci numero 1\n");
        scanf("%d", &numero1);
        printf("Inserisci numero 2\n");
        scanf("%d", &numero2);
    } while (numero2 < numero1);
    i = numero1;
    do
    {
        printf("%d\n", i);       
        i ++;
        
    } while (i < numero2);

    return 0;
}