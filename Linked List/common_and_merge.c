/*
Declare two linked lists A and B
new linked list C must contain only the common elements of A and B
new linked list D must contain all the elements of A and B without duplicates
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
	struct node *temp, *r;
	temp = *q;
	r = (struct node *)malloc(sizeof(struct node));
	r->data = num;
	if(*q == NULL || (*q)->data > num)
	{
		*q = r;
		(*q)->link = temp;
	}
	else
	{
		while(temp->link != NULL)
		{
		    if(temp->data <= num && (temp->link == NULL || temp->link->data > num))
		    {
		        r->link = temp->link;
		        temp->link = r;
		        return;
		    }
		    temp = temp->link;
		}
		temp->link = r;
		r->link = NULL;
	}
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

void common(struct node *p, struct node *q, struct node **s)
{
    struct node *z;
    while(p!=NULL && q!=NULL)
    {
        if(p->data == q->data)
        {
            if(*s == NULL)
            {
                *s = (struct node *)malloc(sizeof(struct node));
                z = *s;
            }
            else
            {
                z->link = (struct node *)malloc(sizeof(struct node));
                z = z->link;
            }
            z->data = p->data;
            p = p->link;
            q = q->link;
        }
        else if(p->data < q->data)
            p = p->link;
        else
            q = q->link;
    }
    z->link = NULL;
    return;
}

void merge(struct node *p, struct node *q, struct node **s)
{
    struct node *z;
    while(p != NULL && q != NULL)
    {
        if(*s == NULL)
        {
            *s = (struct node *)malloc(sizeof(struct node));
            z = *s;
        }
        else
        {
            z->link = (struct node *)malloc(sizeof(struct node));
            z = z->link;
        }
        if(p->data < q->data)
        {
            z->data = p->data;
            p = p->link;
        }
        else if(q->data < p->data)
        {
            z->data = q->data;
            q = q->link;
        }
        else
        {
            if(p->data == q->data)
            {
                z->data = p->data;
                p = p->link;
                q = q->link;
            }
        }
    }
    while(p!=NULL)
    {
        z->link = (struct node *)malloc(sizeof(struct node));
        z = z->link;
        z->data = p->data;
        p = p->link;
    }
    while(q!=NULL)
    {
        z->link = (struct node *)malloc(sizeof(struct node));
        z = z->link;
        z->data = q->data;
        q = q->link;
    }
    z->link = NULL;
    return;
}

int main()
{
    struct node *a, *b, *c, *d;
    a = b = c = d = NULL;
    append(&a,3);
    append(&a,7);
    append(&a,10);
    append(&a,15);
    append(&a,16);
    append(&a,9);
    append(&a,22);
    append(&a,17);
    append(&a,32);
    printf("A : ");
    display(a);
    append(&b,16);
    append(&b,2);
    append(&b,9);
    append(&b,13);
    append(&b,37);
    append(&b,8);
    append(&b,10);
    append(&b,1);
    append(&b,28);
    printf("B : ");
    display(b);
    common(a,b,&c);
    printf("C : ");
    display(c);
    merge(a,b,&d);
    printf("D : ");
    display(d);
    return 0;
}
