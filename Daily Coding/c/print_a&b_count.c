/*
Input = b3c6d15
Output = bbbccccccddddddddddddddd
*/

#include <stdio.h>

int main()
{
    char a[50] = {"b3c6d15"}, temp;
    int i, j, len, num;
    for(len=0; a[len]; len++);
    for(i=0; i<len;)
    {
        if((a[i]>=97 && a[i]<=122) || (a[i]>=65 && a[i]<=90))
        {
            temp = a[i];
            i++;
        }
        else
        {
            num = 0;
            if((a[i]>=48 && a[i]<=57) && (a[i+1]>=48 && a[i+1]<=57))
            {
                num = (a[i]-'0')*10 + a[i+1]-'0';
                i = i+2;
            }
            else 
            {
                num = a[i]-'0';
                i++;
            }
            for(j=0; j<num; j++)
                printf("%c",temp);
        }
    }
    return 0;
}

