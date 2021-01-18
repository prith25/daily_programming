// Remove the characters of the string2 in string 1
#include <stdio.h>
#include <stdlib.h>
char *replace(char *s1, char *s2)
{
    int ind=0, res=0, i;
    char temp;
    int *count = (int*)calloc(sizeof(int),256);
    for(i=0; *(s2+i); i++)
        count[*(s2+i)]++;
    while (*(s1+ind))
    {
        temp = *(s1+ind);
        if(count[temp] == 0)
        {
            *(s1+res) = *(s1+ind);
            res++;
        }
        ind++;
    }
    *(s1+res) = '\0';
    return s1;    
}

int main()
{
    char s1[50], s2[50];
    printf("Enter the string1: ");
    scanf("%s",s1);
    printf("Enter the string2: ");
    scanf("%s",s2);
    printf("%s",replace(s1,s2));
    return 0;
}
