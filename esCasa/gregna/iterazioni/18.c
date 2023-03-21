#include <stdio.h>
int main(int argc, char *argv[])
{
    int s1;
    int h, m, s;
    do
    {
        printf("Inserisci misura in secondi \n");
        scanf("%d", &s1);
    } while (s1 < 0);
    h = s1 / 3600;
    m = s1 % 3600;
    s = m % 60;
    m/=60;
    printf("ore %d minuti %d  secondi %d \n", h, m, s);
    return 0;
}