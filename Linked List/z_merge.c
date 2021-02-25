/*
Create two linked list A and b
A : 7 5 3 1 20
B : 6 25 32 11 9
Result : 7 6 5 25 3 32 1 11 20 9

Note: Not allowed to create any additional node while writing the function
*/
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

struct node *combine(struct node **p, struct node **q)
{
    if((*q)->link != NULL)
        (*q)->link = combine(&(*p)->link, &(*q)->link);
    (*p)->link = *q;
    return *p;
}

int main()
{
    struct node *a, *b;
    a = b = NULL;
    append(&a,7);
    append(&a,5);
    append(&a,3);
    append(&a,1);
    append(&a,20);
    printf("A : ");
    display(a);
    append(&b,6);
    append(&b,25);
    append(&b,32);
    append(&b,11);
    append(&b,9);
    printf("B : ");
    display(b);
    a = combine(&a,&b);
    printf("Result: ");
    display(a);
    return 0;
}

