/*
Mirror pattern
Input : 5
Output:
        0 
      1 0 1 
    2 1 0 1 2 
  3 2 1 0 1 2 3 
4 3 2 1 0 1 2 3 4 
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, len, temp1, temp2, space;
    scanf("%d",&len);
    space = len-1;
    temp1 = 1;
    temp2 = 1;
    for (i=0; i<len; i++)
    {
        for(j = space; j>0; j--)
            printf("  ");
        space--;
        for(j=1; j<=temp1; j++)
            printf("%d ",abs(j-temp2));
        temp1 += 2;
        temp2++;
        printf("\n");
    }
    return 0;
}
