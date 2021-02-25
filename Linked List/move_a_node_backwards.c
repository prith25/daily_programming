/*Create a linked list. Identify a element in a linked list and move the node backwards to n nodes*/
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

void move(struct node **q, int place, int forward)
{
    struct node *temp = *q, *old = NULL;
    int i=0;
    while(temp->link != NULL)
    {
        i++;
        if(temp->data == place)
        {
            if(temp == *q)
                *q = (*q)->link;
            else
                old->link = temp->link;
            break;
        }
        else
        {
            old = temp;
            temp = temp->link;
        }
    }
    old = *q;
    forward = i - forward;
    if(forward <= 1)
    {
        temp->link = old;
        *q = temp;
    }
    else
    {
        for(i=2; i<forward; i++)
            old = old->link;
        temp->link = old->link;
        old->link = temp;
    }
    return;
}

int main()
{
    struct node *p;
    p = NULL;
    append(&p,7);
    append(&p,45);
    append(&p,91);
    append(&p,32);
    append(&p,44);
    append(&p,82);
    append(&p,14);
    append(&p,65);
    append(&p,74);
    printf("Linked list: ");
    display(p);
    move(&p,44,3);
    printf("Result list: ");
    display(p);
    return 0;
}

