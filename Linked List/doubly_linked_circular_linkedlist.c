/*
Doubly linked circular linked list
*/

#include <stdio.h>
#include <malloc.h>

struct dnode 
{
    struct dnode *prev;
    int data;
    struct dnode *next;
};

void append(struct dnode **f, struct dnode **r, int num)
{
    struct dnode *temp;
    temp = (struct dnode *)malloc(sizeof(struct dnode));
    temp->data = num;
    if(*f == NULL)
    {
        temp->prev = NULL;
        temp->next = NULL;
        *f = temp;
        *r = temp;
    }
    else
    {
        (*r)->next = temp;
        temp->prev = *r;
        *r = temp;
        (*r)->next = *f;
        (*f)->prev = *r;
    }
    return;
}

void display(struct dnode *z)
{
    struct dnode *q=z, *p=NULL;
    while(q != p)
    {
        printf("%d ",q->data);
        q = q->next;
        p = z;
    }
    return;
}

int main()
{
    struct dnode *front, *rear;
    front = rear = NULL;
    append(&front,&rear,7);
    append(&front,&rear,18);
    append(&front,&rear,23);
    append(&front,&rear,45);
    append(&front,&rear,11);
    append(&front,&rear,78);
    printf("Doubly linked circular linked list: ");
    display(front);
    return 0;
}
