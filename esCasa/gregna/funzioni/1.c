#include <stdio.h>
int Somma(int a, int b)
{
    return a + b;    
}
int main(int argc, char *argv[])
{
    int a, b;
    printf("Inserire primo numero \n");
    scanf("%d", &a);
    printf("Inserire secondo numero \n");
    scanf("%d", &b);    
    printf("%d", Somma(a,b));
}
