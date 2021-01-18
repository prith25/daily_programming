// Alternate sorting (first, last, second, second last...)
#include <stdio.h>
int main()
{
    int a[50], b[50], i, j, len;
    printf("Enter the length of the array: ");
    scanf("%d",&len);
    printf("Enter the array: ");
    for(i=0; i<len; i++)
        scanf("%d",&a[i]);
    j=0;
    i--;
    while(j < i)
    {
        printf("%d ",a[i]);
        printf("%d ",a[j]);
        j++;
        i--;
        if(i==j)
            printf("%d ",a[i]);
    }
    return 0;
}
