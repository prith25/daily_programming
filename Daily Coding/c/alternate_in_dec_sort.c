/*
Sorting the even index digits in increasing order and odd index digits in descending order
*/

#include <stdio.h>
void sort(int a[50], int len)
{
    int i, j, temp;
    for(i=0; i<len-1; i++)
    {
        for(j=0; j<len-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main()
{
    int i, j, k, len, a[50], b[50];
    printf("Enter the length of the array: ");
    scanf("%d",&len);
    printf("Enter the array: ");
    for(i=0, j=0, k=0; i<len; i++)
    {
        scanf("%d",&a[j++]);
        if(++i < len)
            scanf("%d",&b[k++]);
    }
    sort(a,j);
    sort(b,k);
    for(i=0; i<j; i++)
        printf("%d ",a[i]);
    for(--k; k>=0; k--)
        printf("%d ",b[k]);
    return 0;
}
