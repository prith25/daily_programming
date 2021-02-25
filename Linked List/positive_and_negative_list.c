/* Create a linked list with both postive and negative numbers
Create two linked lists, one containing all postive numbers and the other containing all negative numbers*/

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

void separate(struct node *w, struct node **pos, struct node **neg)
{
	struct node *p = *pos, *n = *neg;
	if(w == NULL)
	{
		printf("The linked list is empty");
		return;
	}
	while(w != NULL)
	{
		if(w->data > 0)
		{
		    if(*pos == NULL)
		    {
		        *pos = (struct node*)malloc(sizeof(struct node));
	            p = *pos;
		    }
		    else
		    {
		        p->link = (struct node*)malloc(sizeof(struct node));
			    p = p->link;
		    }
			p->data = w->data;
		}
		else
		{
		    if(*neg == NULL)
		    {
		        *neg = (struct node*)malloc(sizeof(struct node));
	            n = *neg;
		    }
		    else
		    {
		        n->link = (struct node*)malloc(sizeof(struct node));
			    n = n->link;
		    }
			n->data = w->data;
		}
		w = w->link;
	}
	p->link = NULL;
	n->link = NULL;
	return;
}

int main()
{
	struct node *whole, *positive, *negative;
	whole = positive = negative = NULL;
	append(&whole,8);
	append(&whole,-7);
	append(&whole,45);
	append(&whole,22);
	append(&whole,-37);
	append(&whole,-4);
	append(&whole,15);
	append(&whole,-97);
	append(&whole,85);
	append(&whole,75);
	printf("The linked list : ");
	display(whole);
	separate(whole,&positive,&negative);
	printf("Positive linked list : ");
	display(positive);
	printf("Negative linked list : ");
	display(negative);
	return 0;
}
