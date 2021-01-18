// Remove the duplicate element in an array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *count = (int*)calloc(sizeof(int),256);
    int i, j, len, temp, a[50];
    printf("Enter the length of the array: ");
    scanf("%d",&len);
    printf("Enter the elements: ");
    for(i=0,j=0; i<len; i++)
    {
        scanf("%d",&temp);
        count[temp]++;
        if(count[temp] == 1)
            a[j++] = temp;
    }
    a[j] = '\0';
    for(i=0; a[i]; i++)
        printf("%d ",a[i]);
    return 0;
}
