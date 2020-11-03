// Getting the input and saving it in ascending order.
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
struct node
{
    int data;
    struct node *link;
};
void append(struct node **q, int num)
{
    struct node *temp, *r;
    temp = *q;
    r = (struct node*)malloc(sizeof(struct node));
    r->data = num;
    if((*q) == NULL || (*q)->data > num)
    {
        (*q) = r;
        (*q)->link = temp;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data <= num && (temp->link == NULL || temp->link->data > num))
            {
                r->link = temp->link;
                temp->link = r;
                return;
            }
            temp = temp->link;
        }
    }
    return;
}
void display(struct node *q)
{
    printf("Linked list : ");
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
    system("cls");
    struct node *p;
    p = NULL;
    int num;
    char c;
    do
    {
        printf("\nEnter the data: ");
        scanf(" %d",&num);
        append(&p,num);
        printf("Any more nodes (Y/N) ");
        fflush(stdin);
        c = getchar();
    }while(c=='Y' || c=='y');
    display(p);
    return 0;
}
