/*Program to find the largest and Second largest element in an array*/
#include <stdio.h>
int main()
{
    int i, a[10], len, largest = -9999, second_largest = -9999;
    printf("Enter the length of the array: ");
    scanf("%d",&len);
    printf("Enter the array: ");
    for(i=0; i<len; i++)
        scanf("%d",&a[i]);
    for(i=0; i<len; i++)
    {
        if(a[i] > largest)
        {
            second_largest = largest;
            largest = a[i];
        }
        if(a[i] != largest && a[i] > second_largest)
            second_largest = a[i];
    }
    printf("Largest element : %d\nSecond Largest element : %d",largest,second_largest);
    return 0;
}
