/*

1
1 1
2 1
1 2 1 1
1 1 1 2 2 1
3 1 2 2 1 1

*/
#include <stdio.h>
int main()
{
    int output[50], next_op[50], temp, count = 0, lines, i, j, l, k;
    printf("Enter the number of lines : ");
    scanf("%d",&lines);
    output[0] = 1;
    for(i=0; i<lines; i++)
    {
        for(k=0; output[k]; k++)
            printf("%d ",output[k]);
        l = 0;
        for(j=0,temp = output[0]; j<=k; j++)
        {
            if((temp == output[j]) && (output[j] != '\0'))
                count++;
            else
            {
                next_op[l++] = count;
                next_op[l++] = temp;
                count = 0;
                if(j<k)
                {
                    temp = output[j];
                    j--;
                }
            }
        }
        next_op[l] = '\0';
        for(j=0; j<=l; j++)
            output[j] = next_op[j];
        printf("\n");
    }
    return 0;
}
