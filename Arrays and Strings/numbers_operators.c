/*
Given a String with numbers and operators. Perform the operation on the numbers in their respective order. Operator precedence need not be considered. The input string will have the numbers followed by the operators.

Input: "12345 * + - + "
Result: 6 [Explanation: 1 * 2 + 3 - 4 + 5 = 6]
Input: "374291 - - * + -"
Result: -8 [Explanation: 3 - 7 - 4 * 2 + 9 - 1 = -8]

*/
#include <stdio.h>
#include <math.h>

int calc(int x, char y, char operator)
{
    int a, b;
    a = x;
    b = y - '0';
    if(operator == '+')
        a = a + b;
    else if(operator == '-')
        a = a - b;
    else if(operator == '*')
        a = a * b;
    else if(operator == '/')
        a = a / b;
    else
    {
        if(operator == '^')
            a = pow(a,b);
    }
    return a;
}

int main()
{
    char input[100] = {"374291 - - * + -"}, b, operator = '#';
    int i, j, len, change = 0, a;
    for(len=0; input[len]; len++);
    for(i=0, j=1, a=input[0]-'0'; i<len; )
    {
        if(change)
        {
            b = input[++i];
            a = calc(a,b,operator);
            change = 0;
        }
        else
        {
            if(j == len)
                break;
            for(; j<len; j++)
            {
                if(input[j]=='+' || input[j]=='-' || input[j]=='*' || input[j]=='/' || input[j]=='^')
                {
                    operator = input[j];
                    j++;
                    break;
                }
            }
            change = 1;
        }
    }
    printf("%d\n",a);
    return 0;
}
