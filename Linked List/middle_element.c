/* Finding the middle element in a single linked list*/
#include <stdio.h>
#include <malloc.h>

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

int middle_element(struct node *s)
{
    struct node *p, *q;
    p = q = s;
    while(1)
    {
        if(q->link!=NULL && q->link->link!=NULL)
        {
            p = p->link;
            q = q->link->link;
        }
        else
            break;
    }
    return p->data;
}

int main()
{
    struct node *p;
    p = NULL;
    int i;
    for(i=1; i<=7; i++)
        append(&p,i);
    printf("Linked List : ");
    display(p);
    i = middle_element(p);
    printf("Midde element : %d",i);
    return 0;
}
