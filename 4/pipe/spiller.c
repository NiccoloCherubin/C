#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int a;
    while (1)
    {
        printf("%d\n", getpid());
        printf("%p", &a);
        sleep(1);
    }
       
    return 0;
}