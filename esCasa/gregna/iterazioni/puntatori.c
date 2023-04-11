#include <stdlib.h>
#include <stdio.h>
void main()
{
    char s[] = "Pippo";
    char *p = s + 2;
    p++;
    *p = *s;
    printf("%s\n", s);
}