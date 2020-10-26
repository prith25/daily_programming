/*Operations in an array
1. Inserting a new element
2. Deleting an element
3. Search an element
4. Reverse the array
5. Display the elements in the array*/
#include <stdio.h>
#include <windows.h>
#define N 5
void insert(int *, int , int );
void delete(int *, int);
void reverse(int *);
void search(int *, int);
void display(int *);
int main()
{
    system("cls");
    int i, j, a[N], choice, num;
    printf("Enter the elements: ");
    for(i=0 ; i<N; i++)
        scanf("%d",&a[i]);
    j = 1;
    while(j)
    {
        printf("\nOperations in an array");
        printf("\n1. Insert an element.");
        printf("\n2. Delete an element.");
        printf("\n3. Search an element.");
        printf("\n4. Reverse the array.");
        printf("\n5. Display the array.");
        printf("\n6. Exit.");
        printf("\nEnter your choice: ");
        scanf(" %d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the position and the element: ");
            scanf("%d %d",&i,&num);
            insert(a,i,num);
            printf("\nThe Array is : ");
            display(a);
            break;
        
        case 2:
            printf("\nEnter the element to be deleted: ");
            scanf("%d",&num);
            delete(a,num);
            printf("\nThe Array is : ");
            display(a);
            break;

        case 3:
            printf("\nEnter the element to be searched: ");
            scanf("%d",&num);
            search(a,num);
            printf("\nThe Array is : ");
            display(a);
            break;
        
        case 4:
            printf("\nDo you want to reverse the array (0/1): ");
            scanf(" %d",&i);
            if(i == 1)
                reverse(a);
            printf("\nThe Array is : ");
            display(a);
            break;
        
        case 5:
            printf("\nThe Array is : ");
            display(a);
            break;

        case 6:
            j = 0;
            break;

        default:
            printf("\nEnter the correct choice");
            break;
        }
    }
    return 0;
}
void insert(int *arr, int pos, int num)
{
    int i;
    for(i=N-1; i>=pos; i--)
        arr[i] = arr[i-1];
    arr[i] = num;
    return;
}
void delete(int *arr, int num)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(arr[i] == num)
        {
            for(; i<N-1; i++)
                arr[i] = arr[i+1];
            arr[i] = 0;
            return;
        }
    }
    printf("\nThe number %d is not found",num);
    return;
}
void search(int *arr, int num)
{
    int i;
    for(i=0; i<N; i++)
    {
        if(arr[i] == num)
        {
            printf("\nThe number %d is found in position %d",num,i+1);
            return;
        }
    }
    printf("\nThe number %d is not found",num);
    return;
}
void reverse(int *arr)
{
    int i, temp;
    for(i=0; i<N/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[N-1-i];
        arr[N-1-i] = temp;
    }
    for(i=0; i<N; i++)
        printf("%d ",arr[i]);
    return;
}
void display(int *arr)
{
    int i;
    for(i=0; i<N; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return;
}
