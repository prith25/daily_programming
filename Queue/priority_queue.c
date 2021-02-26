/* Priority Queue */
#include <stdio.h>
#include <string.h>
#define maxx 5

struct data
{
    char job[maxx];
    int priority_no;
    int order_no;
};

struct pque
{
    struct data d[maxx];
    int front;
    int rear;
};

void initqueue(struct pque *pq)
{
    int i;
    pq->front = pq->rear = -1;
    for(i=0; i<maxx; i++)
    {
        strcpy(pq->d[i].job,"");
        pq->d[i].priority_no = pq->d[i].order_no = 0;
    }
}

void addpq(struct pque *pq, struct data dt)
{
    struct data temp;
    int i, j;
    if(pq->rear == maxx-1)
    {
        printf("Queue is full");
        return;
    }
    pq->rear++;
    pq->d[pq->rear] = dt;
    if(pq->front == -1)
        pq->front = 0;
    for(i=pq->front; i<=pq->rear; i++)
    {
        for(j=i+1; j<=pq->rear; j++)
        {
            if(pq->d[i].priority_no > pq->d[j].priority_no)
            {
                temp = pq->d[i];
                pq->d[i] = pq->d[j];
                pq->d[j] = temp;
            }
            else
            {
                if(pq->d[i].priority_no == pq->d[j].priority_no)
                {
                    if(pq->d[i].order_no > pq->d[j].order_no)
                    {
                        temp = pq->d[i];
                        pq->d[i] = pq->d[j];
                        pq->d[j] = temp;
                    }
                }
            }
        }
    }
    return;
}

struct data delpq(struct pque *pq)
{
    struct data t;
    strcpy(t.job,"");
    t.priority_no = t.order_no = 0;
    if(pq->front == -1)
    {
        printf("Queue is empty");
        return t;
    }
    t = pq->d[pq->front];
    //pq->d[pq->front] = t;
    if(pq->front == pq->rear)
        pq->front = pq->rear = -1;
    else    
        pq->front++;
    return t;
}

int main()
{
    struct pque q;
    struct data dt, temp;
    int i;
    initqueue(&q);
    printf("\nEnte the task and the priority of the task\n");
    for(i=1; i<=maxx; i++)
    {
        scanf("%s %d",dt.job,&dt.priority_no);
        dt.order_no = i;
        addpq(&q,dt);
    }
    printf("\nThe awaiable tasks are \n");
    for(i=0; i<maxx; i++)
    {
        temp = delpq(&q);
        printf("%s %d\n",temp.job,temp.priority_no);
    }
    return 0;
}
