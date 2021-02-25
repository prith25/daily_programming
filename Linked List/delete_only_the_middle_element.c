/*You have access only to the middle element. Delete the middle element*/
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

void remove_element(struct node **q)
{
    if(*q!=NULL && (*q)->link!=NULL)
    {
        (*q)->data = (*q)->link->data;
        (*q)->link = (*q)->link->link;
    }
    return;
}

int middle_element(struct node *s)
{
    struct node *p, *q;
    p = q = s;
    int mid;
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
    mid = p->data;
    remove_element(&p);
    return mid;
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
    printf("\nLinked List : ");
    display(p);
    return 0;
}
