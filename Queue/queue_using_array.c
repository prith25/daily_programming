/* Queue implementation using array */

#include <stdio.h>
#define Max 10

void addq(int arr[Max], int num, int *pfront, int *prear)
{
    if(*prear == Max - 1)
    {
        printf("Queue is full\n");
        return;
    }
    (*prear)++;
    arr[*prear] = num;
    if(*pfront == -1)
        *pfront = 0;
    return;
}

void delq(int arr[Max], int *pfront, int *prear)
{
    if(*pfront == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    int data;
    data = arr[*pfront];
    arr[*pfront] = 0;
    if(*pfront == *prear)
        *pfront = *prear = -1;
    else
        (*pfront)++;
    printf("\nDeleted item = %d\n",data);
    return;
}

void display(int arr[Max])
{
    int i;
    printf("Queue : ");
    for(i=0; i<Max; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return;
}

int main()
{
    int a[Max], front = -1, rear = -1;
    int i=0;
    for(i=0; i<Max; i++)
        a[i] = 0;
    addq(a,23,&front,&rear);
    addq(a,14,&front,&rear);
    addq(a,7,&front,&rear);
    addq(a,84,&front,&rear);
    addq(a,36,&front,&rear);
    addq(a,95,&front,&rear);
    addq(a,85,&front,&rear);
    addq(a,64,&front,&rear);
    addq(a,31,&front,&rear);
    addq(a,15,&front,&rear);
    addq(a,78,&front,&rear);
    display(a);
    delq(a,&front,&rear);
    delq(a,&front,&rear);
    delq(a,&front,&rear);
    display(a);
    return 0;
}








