/*
A : 7->1->6
B : 5->9->2
Add the linked list
(716 + 592 = 1308)
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

void add(struct node *p, struct node *q)
{
    int total=0, rem=0, digit=1, num;
    while(p!=NULL || q!=NULL || rem!=0)
    {
        num = 0;
        if(p!=NULL)
        {
            num += p->data;
            p = p->link;
        }
        if(q!=NULL)
        {
            num += q->data;
            q = q->link;
        }
        total += ((num+rem)%10)*digit;
        digit *= 10;
        rem = (num+rem)/10;
    }
    printf("Total : %d",total);
    return;
}

int main()
{
    struct node *first, *second;
    first = second = NULL;
	int num1, num2, total;
    append(&first,7);
	append(&first,1);
	append(&first,6);
	append(&second,5);
	append(&second,9);
	append(&second,2);
	add(first,second);
	return 0;
}
