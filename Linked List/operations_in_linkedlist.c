/*Operations in the linked list
1. Adding an element in the linked list.
2. Adding an element in the begining of the linked list.
3. Adding an element after any specific location in the linked list.
4. Deleting the particular element.
5. Display the linked list.*/

#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node* link;
};
void append(struct node **q, int n)
{
    struct node *temp, *r;
    if(*q == NULL)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = n;
        temp->link = NULL;
        *q = temp;
    }
    else
    {
        temp = *q;
        while(temp->link != NULL)
            temp = temp->link;
        r = (struct node*)malloc(sizeof(struct node));
        r->data = n;
        r->link = NULL;
        temp->link = r;
    }
    return;
}
void appendbeg(struct node **q, int n)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->link = *q;
    *q = temp;
    return;
}
void appendafter(struct node **q, int n, int loc)
{
    struct node *temp, *r;
    temp = *q;
    int i;
    for(i=1; i<loc; i++)
    {
        temp = temp->link;
        if(temp == NULL)
        {
            printf("\nThe list has less than %d data\n",loc);
            return;
        }
            
    }
    r = (struct node*)malloc(sizeof(struct node));
    r->data = n;
    r->link = temp->link;
    temp->link = r;
    return;
}
void delete(struct node **q, int n)
{
    struct node *temp, *old;
    temp = *q;
    while(temp != NULL)
    {
        if(temp->data == n)
        {
            if(temp == *q)
                *q = temp->link;
            else
                old->link = temp->link;
            free(temp);
            return;
        }
        old = temp;
        temp = temp->link;
    }
    printf("The data is not found");
    return;
}
void display(struct node *q)
{
    while(q != NULL)
    {
        printf("%d ",q->data);
        q = q->link;
    }
    printf("\n");
    return;
}
int main()
{
    struct node *p;
    p = NULL;
    int i, j, choice, num, loc;
    j = 1;
    while(j)
    {
        printf("\n1. Add data to the list.");
        printf("\n2. Add data in the begining.");
        printf("\n3. Add data after a specific location.");
        printf("\n4. Delete a particular data.");
        printf("\n5. Display the list. ");
        printf("\n6. Exit.");
        printf("\nEnter your option: ");
        scanf("%d",&choice);
        if(choice == 1 || choice == 2 || choice == 3)
        {
            printf("\nEnter the data: ");
            scanf("%d",&num);
        }
        switch (choice)
        {
        case 1:
            append(&p,num);
            break;
        
        case 2:
            appendbeg(&p,num);
            break;

        case 3:
            printf("\nEnter the lcoation: ");
            scanf("%d",&loc);
            appendafter(&p,num,loc);
            break;

        case 4:
            printf("\nEnter the data to be deleted: ");
            scanf("%d",&num);
            delete(&p,num);
            break;
        
        case 5:
            printf("\nThe linked list is : ");
            display(p);
            break;
        
        case 6:
            j = 0;
            break;

        default:
            printf("\nEnter the correct option");
            break;
        }
    }
    return 0;
}
