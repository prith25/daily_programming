/*
Given a number, the problem has to print two prime numbers whose sum will be equal to given number.
*/
#include <stdio.h>
int is_prime(int num)
{
    int i;
    for(i=3; i<=(num/2); i++)
    {
        if(num%i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int num, i;
    printf("Enter the number: ");
    scanf("%d",&num);
    for(i=3; i<=num; i++)
    {
        if(is_prime(i) && is_prime(num-i))
        {
            printf("%d %d",i,num-i);
            break;
        }
    }
    return 0;
}
