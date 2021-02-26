/* Queue using linked list */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void initqueue(struct queue *q)
{
    q->front = q->rear = NULL;
}

void addq(struct queue *q, int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = NULL;
    if(q->front == NULL)
        q->front = q->rear = temp;
    else
    {
        q->rear->link = temp;
        q->rear = q->rear->link;
    }
    return;
}

void delq(struct queue *q)
{
    struct node *temp;
    if(q->front == NULL)
    {
        printf("Queue is empty");
        return;
    }
    int data;
    data = q->front->data;
    temp = q->front;
    q->front = q->front->link;
    free(temp);
    printf("Deleted item : %d\n",data);
    return;
}

void deletequeue(struct queue *q)
{
    struct node *temp;
    if(q->front == NULL)
        return;
    while(q->front != NULL)
    {
        temp = q->front;
        q->front = q->front->link;
        free(temp);
    }
    return;
}

void display(struct queue *q)
{
    struct queue *temp;
    temp->front = q->front;
    while(q->front != NULL)
    {
        printf("%d ",q->front->data);
        q->front = q->front->link;
    }
    q->front = temp->front;
    printf("\n");
    return;
}

int main()
{
    struct queue a;
    initqueue(&a);
    addq(&a,23);
    addq(&a,10);
    addq(&a,32);
    addq(&a,41);
    addq(&a,12);
    addq(&a,17);
    addq(&a,85);
    //display(&a);
    delq(&a);
    delq(&a);
    delq(&a);
    delq(&a);
    display(&a);
    deletequeue(&a);
    display(&a);
    return 0;
}

