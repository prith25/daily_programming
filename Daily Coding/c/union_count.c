// Find the union of two arrays and print the number elements in the resultant array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *count = (int*)calloc(sizeof(int),256);
    int a[50], i, len1, len2, temp;
    printf("Enter the length of both the arrays: ");
    scanf("%d %d",&len1,&len2);
    printf("Enter the first array: ");
    for(i=0; i<len1; i++)
    {
        scanf("%d",&a[i]);
        count[a[i]]++;
    }
    printf("Enter the second array: ");
    for(i=0; i<len2; i++)
    {
        scanf("%d",&temp);
        if(count[temp] == 0)
            len1++;
    }
    printf("The length of the union is %d",len1);
    return 0;
}
