#include <stdio.h>
int main(int argc, char *argv[])
{
    int n;
    do
    {
        printf("inserire numero maggiore di 1 \n");
        scanf("%d", &n);
    } while (n <= 1);
    n--;
    printf("%d\n", n);
    return 0;
}