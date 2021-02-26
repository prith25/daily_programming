/* Circular Queue */

#include <stdio.h>
#define Max 5

void addq(int arr[Max], int num, int *pfront, int *prear)
{
    if((*prear==Max-1 && *pfront == 0) || ((*prear)+1 == *pfront))
    {
        printf("Queue is full\n");
        return;
    }
    if(*prear == Max-1)
        *prear = 0;
    else
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
    {
        if(*pfront == Max-1)
            *pfront = 0;
        else
            (*pfront)++;
    }
    printf("Deleted element : %d\n",data);
    return;
}

void display(int arr[Max])
{
    printf("\nQueue : ");
    for(int i=0; i<Max; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return;
}

int main()
{
    int a[Max];
    for(int i=0; i<Max; i++)
        a[i] = 0;
    int front =-1, rear = -1;
    addq(a,23,&front,&rear);
    addq(a,14,&front,&rear);
    addq(a,7,&front,&rear);
    addq(a,84,&front,&rear);
    addq(a,36,&front,&rear);
    addq(a,78,&front,&rear);
    display(a);
    delq(a,&front,&rear);
    delq(a,&front,&rear);
    delq(a,&front,&rear);
    display(a);
    addq(a,95,&front,&rear);
    addq(a,85,&front,&rear);
    addq(a,64,&front,&rear);
    addq(a,31,&front,&rear);
    addq(a,15,&front,&rear);
    display(a);
    delq(a,&front,&rear);
    delq(a,&front,&rear);
    display(a);
    return 0;
}
