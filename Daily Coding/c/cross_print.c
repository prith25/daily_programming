//Print the word in cross pattern
#include <stdio.h>
int main()
{
    int i, j, len, l;
    char word[50];
    printf("Enter the word: ");
    scanf("%s",word);
    for(len=0; word[len]; len++);
    l = len-1;
    for(i=0; i<len; i++,l--)
    {
        for(j=0; j<len; j++)
        {
            if(i==j || j==l)
                printf("%c ",word[j]);
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}
