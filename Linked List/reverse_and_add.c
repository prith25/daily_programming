/*
A : 7->1->6
B : 5->9->2
Reverse both the linked lists and add them
(617 + 295 = 912)
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

int combine(struct node *q)
{
	int num=0, num_temp, digit = 1;
	struct node *temp = q;
	while(temp != NULL)
	{
		num_temp = temp->data;
		//num += num_temp*digit;
		num = num*10 + num_temp;
		digit *= 10;
		temp = temp->link;
	}
	return num;
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
	num1 = combine(first);
	num2 = combine(second);
	total = num1 + num2;
	printf("%d  %d   ",num1,num2);
	printf("Sum : %d",total);
	return 0;
}
