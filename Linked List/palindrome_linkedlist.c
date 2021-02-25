/* Find whether the linked list is a palindrome or not */
#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *link;
};

struct queue
{
    int data;
    struct queue *link;
};

void append(struct node **q, int num)
{
	struct node *temp;
	temp = *q;
	if(*q == NULL)
	{
		*q = (struct node*)malloc(sizeof(struct node));
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

void display(struct node *q)
{
	while(q != NULL)
	{
		printf("%d ",q->data);
		q = q->link;
	} 
	printf("\n");
}

void push(struct queue **q, int num)
{
    struct queue *temp;
    temp = (struct queue*)malloc(sizeof(struct queue));
    temp->data = num;
    temp->link = *q;
    *q = temp;
    return;
}

int pop(struct queue **q)
{
    struct queue *temp;
    if(*q == NULL)
    {
        printf("Stack is empty");
        return 0;
    }
    int data;
    data = (*q)->data;
    temp = *q;
    *q = (*q)->link;
    free(temp);
    return data;
}

void palindrome(struct node *s)
{
    struct node *p, *q;
    struct queue *z = NULL;
    p = q = s;
    int temp;
    while(q->link!=NULL && q->link->link!=NULL)
    {
        push(&z,p->data);
        p = p->link;
        q = q->link->link;
    }
    if(q->link == NULL)
        p = p->link;
    else
    {
        push(&z,p->data);
        p = p->link;
    }
    while(p!=NULL)
    {
        temp = pop(&z);
        if(temp != p->data)
        {
            printf("Not a palindrome");
            return;
        }
        p = p->link;
    }
    printf("It is a palindrome");
    return;
}

int main()
{
    struct node *p;
    p = NULL;
    append(&p,1);
    append(&p,2);
    append(&p,3);
    append(&p,4);
    append(&p,3);
    append(&p,2);
    append(&p,1);
    printf("Linked list : ");
    display(p);
    palindrome(p);
    return 0;
}
