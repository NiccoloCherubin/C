#include <stdio.h>

/// @brief compute the sum of the two numbers
/// @param a first parameter
/// @param b second parameter
/// @return the sum of the two numbers
int add(int a, int b)
{
    return a+b;
}

/// @brief compute the multiplication of the two numbers
/// @param a first parameter
/// @param b second parameter
/// @return the multiplication of the two numbers
int mul(int a, int b)
{
    return a*b;
}
/// @brief compute the minus of the two numbers
/// @param a first parameter
/// @param b second parameter
/// @return the minus of the two numbers
int sub (int a, int b)
{
    return a-b;
}
/// @brief compute the division of the two numbers
/// @param a first parameter
/// @param b second parameter
/// @return the division of the two numbers
double division(int a, int b)
{
    return a/b;
}
/// @brief main function
void main(){
    printf("%d\n",add(6,3));
    printf("%d\n",mul(6,3));
    printf("%d\n",sub(6,3));
    printf("%f\n",division(6,3));
}
