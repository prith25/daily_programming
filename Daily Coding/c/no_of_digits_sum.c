/*
Get two numbers as input. Find the sum of the numbers.
If the number of digits in the sum is greater than the number of digits in the first number then print only the first number, else print the sum
*/
#include <stdio.h>
int digit(int num)
{
    int count = 0;
    while(num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}
int main()
{
    int a, b, sum, digits_a, digits_sum;
    printf("Enter the numbers : ");
    scanf("%d %d",&a,&b);
    digits_a = digit(a);
    sum = a+b;
    digits_sum = digit(sum);
    if(digits_sum == digits_a)
        printf("%d",sum);
    else
        printf("%d",a);
    return 0;
}
