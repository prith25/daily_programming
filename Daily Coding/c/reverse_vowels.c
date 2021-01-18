/*
Reverse only the vowels present in the string
*/
#include <stdio.h>
int check(char l)
{
    if (l=='a' || l=='e' || l=='i' || l=='o' || l=='u')
        return 1;
    return 0;
}
int main()
{
    char word[50], temp;
    int i, j, len;
    printf("Enter the word: ");
    scanf("%s",word);
    for(len=0; word[len]; len++);
    i = 0;
    j = len-1;
    while(i < j)
    {
        if (!check(word[i]))
            i++;
        else if(!check(word[j]))
            j--;
        else
        {
            temp = word[i];
            word[i] = word[j];
            word[j] = temp;
            i++;
            j--;
        }
    }
    printf("%s",word);
    return 0;
}
