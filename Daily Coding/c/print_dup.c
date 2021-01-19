//Print the duplicate element in the array. If there is no duplicate element then print -1
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *count = (int*)calloc(sizeof(int),256);
    int i, temp, len, flag = 1;
    printf("Enter the length of the array: ");
    scanf("%d",&len);
    printf("Enter the array: ");
    for(i=0; i<len; i++)
    {
        scanf("%d",&temp);
        count[temp]++;
        if(count[temp] > 1)
        {
            printf("%d ",temp);
            flag = 0;
        }
    }
    if (flag)
        printf("-1");
    return 0;
}
