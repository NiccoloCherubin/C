#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char string1[100], string2[100];
    char min[50], max[50];
    char common[50]; // in order to save common letters among two strings
    printf("Input string 1 \n");
    scanf("%s", string1);
    printf("Input string 2 \n");
    scanf("%s", string2);
    if (strlen(string1) != strlen(string2))
    {
        if (strlen(string1) > strlen(string2))
        {
            strcpy(max, string1);
            strcpy(min, string2);
        }
        else
        {
            strcpy(min, string1);
            strcpy(max, string2);
        }
    }
    else
    {
        strcpy(min, string1);
        strcpy(max, string1);
    }
    printf("lettere in comune :");
    for (int i = 0; i < strlen(max); i++)
    {
        for (int k = 0; k < strlen(min); k++)
        {
            if (min[i] == max[k]) // check if there letters in common
            {
                printf("%s", &min[i]);
            }
        }
    }
    return 0;
}