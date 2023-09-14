#include <stdio.h>
int main(int argc, char *argv[])
{
    int n, N; // N per intervallo
    do
    {
        printf("Inserisci un numero intero poisitivo \n");
        scanf("%d", &n);
    } while (n < 0);
    n = -n;
    N = n;
    do
    {
        printf("%d \n", n);
        n++;

    } while (n <= -N && n >= N);

    return 0;
}