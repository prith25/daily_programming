/*
In two sorted arrays A and B, there is only 1 extra element in array A. Find the index of that one extra element
*/
#include <stdio.h>
int main()
{
    int a[50], b[50], temp, len, i;
    printf("Enter the length of array: ");
    scanf("%d",&len);
    printf("Enter the elements of first array: ");
    for(i=0; i<len; i++)
        scanf("%d",&a[i]);
    printf("Enter the elements of second array: ");
    for(i=0; i<len-1; i++)
    {
        scanf("%d",&b[i]);
        if(a[i] != b[i])
        {
            printf("Index : %d",i);
            break;
        }
    }
    return 0;
}
