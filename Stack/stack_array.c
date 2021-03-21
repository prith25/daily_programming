// Implementing and displaying stack using array
#include <stdio.h>
#define max 10

struct stack
{
    int a[max];
    int top;
};

void initstack(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, int num)
{
    if(s->top == max - 1)
    {
        printf("Stack is full");
        return;
    }
    s->top++;
    s->a[s->top] = num;
    return;
}

int pop(struct stack *s)
{
    int x;
    if(s->top == -1)
    {
        printf("Stack is empty");
        return 0;
    }
    x = s->a[s->top];
    s->a[s->top] = 0;
    s->top--;
    return x;
}

void print(struct stack *s)
{
    if (s->top == -1)
        return;
    int temp;
    temp = s->a[s->top];
    s->top--;
    print(s);
    printf("%d ",temp);
    s->top++;
    s->a[s->top] = temp;
    return;
}

int main()
{
    struct stack s;
    initstack(&s);
    int i, temp;
    for(i=0; i<10; i++)
        push(&s,i+1);
    printf("Elements : ");
    print(&s);
    printf("\nPopping Elements : ");
    for(i=0; i<10; i++)
    {
        temp = pop(&s);
        printf("%d ",temp);
    }
    return 0;
}
