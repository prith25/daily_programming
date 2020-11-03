// Reversing the given linked list.
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
struct node
{
    int data;
    struct node *link;
};
void append(struct node **q, int num)
{
    struct node *temp;
    temp = *q;
    if(*q == NULL)
    {
        (*q) = (struct node*)malloc(sizeof(struct node));
        temp = *q;
    }
    else
    {
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = (struct node*)malloc(sizeof(struct node));
        temp = temp->link;
    }
    temp->data = num;
    temp->link = NULL;
    return;
}
void reverse(struct node **x)
{
    struct node *q, *r, *s;
    q = (*x);
    r = NULL;
    while(q != NULL)
    {
        s = r;
        r = q;
        q = q->link;
        r->link = s;
    }
    (*x) = r;
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
    int i;
    for(i=5; i<=100; i+=5)
        append(&p,i);
    display(p);
    reverse(&p);
    printf("The reversed ");
    display(p);
    return 0;
}
