/*
Get two numbers as input. Find the sum of the numbers.
If the number of digits in the sum is greater than the number of digits in the first number then print only the first number, else print the sum
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
