#include <stdio.h>
#include <malloc.h>
#include <windows.h>
int* create(int size)
{
    int *arr, i;
    arr = (int*)malloc(sizeof(int)*size);
    printf("\nEnter the elements of the array: ");
    for(i=0; i<size; i++)
        scanf("%d",&arr[i]);
    return arr;
}
void sort(int *arr, int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}
int* merge(int *a, int *b, int n1, int n2)
{
    int *c, i=0, j=0, k=0, size;
    size = n1 + n2;
    c = (int*)malloc(sizeof(int)*size);
    while(i<n1 && j<n2)
    {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else if(b[j] < a[i])
            c[k++] = b[j++];
        else
        {
            if(a[i] == b[j])
            {
                c[k++] = a[i++];
                j++;
            }
        }
    }
    while(i<n1)
        c[k++] = a[i++];
    while(j<n2)
        c[k++] = b[j++];
    c[k] = '\0';
    return c;
}
void display(int *arr, int n)
{
    int i;
    for(i=0; i<n && arr[i]!='\0'; i++)
        printf(" %d",arr[i]);
    printf("\n");
    return;
}
int main()
{
    system("cls");
    int *a, *b, *c, n1, n2;
    printf("\nEnter the size of Array1: ");
    scanf("%d",&n1);
    a = create(n1);
    display(a,n1);
    printf("\nEnter the size of Array2: ");
    scanf("%d",&n2);
    b = create(n2);
    display(b,n2);
    sort(a,n1);
    sort(b,n2);
    printf("\nAfter Sorting\nArray1: ");
    display(a,n1);
    printf("\nArray2: ");
    display(b,n2);
    c = merge(a,b,n1,n2);
    printf("\nMerged array: ");
    display(c,n1+n2);
    return 0;
}
