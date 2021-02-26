/* Deque */

#include <stdio.h>
#define Max 7

void display(int *arr)
{
    int i;
    printf("\nQueue : ");
    for(i=0; i<Max; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int count(int *arr)
{
    int c=0, i;
    for(i=0; i<Max; i++)
    {
        if(arr[i] != 0)
            c++;
    }
    return c;
}

void addatbeg(int *arr, int num, int *pfront, int *prear)
{
    if(*pfront == 0 && *prear == Max-1)
    {
        printf("\nQueue is full");
        return;
    }
    if(*pfront == -1)
    {
        *pfront = *prear = 0;
        arr[*pfront] = num;
        return;
    }
    if(*prear != Max-1)
    {
        int k, i, c;
        c = count(arr);
        k = (*prear)+1;
        for(i=1; i<=c; i++)
        {
            arr[k] = arr[k-1];
            k--;
        }
        arr[k] = num;
        *pfront = k;
        (*prear)++;
    }
    else
    {
        (*pfront)--;
        arr[*pfront] = num;
    }
    return;
}

void addatend(int *arr, int num, int *pfront, int *prear)
{
    if(*pfront == 0 && *prear == Max-1)
    {
        printf("\nQueue is full");
        return;
    }
    if(*pfront == -1)
    {
        *pfront = *prear = 0;
        arr[*pfront] = num;
        return;
    }
    if(*prear == Max-1)
    {
        int c, k, i;
        c = count(arr);
        k = (*pfront)-1;
        for(i=0; i<c; i++)
        {
            arr[k] = arr[k+1];
            k++;
        }
        (*pfront)--;
        (*prear)--;
    }
    (*prear)++;
    arr[*prear] = num;
    return;
}

void delatbeg(int *arr, int *pfront, int *prear)
{
    if(*pfront == -1)
    {
        printf("\nQueue is empty");
        return;
    }
    int data;
    data = arr[*pfront];
    arr[*pfront] = 0;
    if(*pfront == *prear)
        *pfront = *prear = -1;
    else 
        (*pfront)++;
    printf("\nDeleted item : %d",data);
    return;
}

void delatend(int *arr, int *pfront, int *prear)
{
    if(*pfront == -1)
    {
        printf("\nQueue is empty");
        return;
    }
    int data;
    data = arr[*prear];
    arr[*prear] = 0;
    (*prear)--;
    if((*prear) == -1)
        *pfront = -1;
    printf("\nDeleted item = %d",data);
    return;
}

int main()
{
    int a[Max], front, rear, i;
    front = rear = -1;
    for(i=0; i<Max; i++)
        a[i] = 0;
    addatbeg(a,23,&front,&rear);
    addatbeg(a,17,&front,&rear);
    addatbeg(a,85,&front,&rear);
    addatbeg(a,62,&front,&rear);
    display(a);
    addatend(a,39,&front,&rear);
    addatend(a,54,&front,&rear);
    addatend(a,91,&front,&rear);
    addatend(a,37,&front,&rear);
    display(a);
    delatbeg(a,&front,&rear);
    delatbeg(a,&front,&rear);
    display(a);
    delatend(a,&front,&rear);
    delatend(a,&front,&rear);
    display(a);
    return 0;
}
