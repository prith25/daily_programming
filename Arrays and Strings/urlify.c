#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
    system("cls");
    int i, len, space;
    char s[300] = "Mr. John Smith             ";
    /*printf("Enter the string: ");
    gets(s);*/
    len = strlen(s);
    for(i=0; i<len; i++)
    {
        if(s[i] == ' ')
            space++;
    }
    while(s[--i] == ' ')
        space--;
    len = i + space*2;
    for(; len>=0; )
    {
        if(s[i] == ' ')
        {
            s[len--] = '0';
            s[len--] = '2';
            s[len--] = '%';
            i--; 
        }
        else
            s[len--] = s[i--];      
    }
    printf("%s",s);
    return 0;
}
