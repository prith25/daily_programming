// Implementing stack using linked list and printing the elements
#include <stdio.h>
#include <malloc.h>

struct stack
{
    int data;
    struct stack *link;
};

void push(struct stack **top, int num)
{
    struct stack *temp;
    temp = (struct stack*)malloc(sizeof(struct stack));
    temp->data = num;
    temp->link = *top;
    *top = temp;
    return;
}

int pop(struct stack **top)
{
    struct stack *temp;
    if(*top == NULL)
    {
        printf("Stack is empty");
        return 0;
    }
    int num;
    num = (*top)->data;
    temp = *top;
    *top = (*top)->link;
    free(temp);
    return num;
}

void print(struct stack **s)
{
    if(*s == NULL)
        return;
    int temp;
    temp = pop(s);
    print(s);
    printf("%d ",temp);
    push(s,temp);
    return;
}

void delete(struct stack **s)
{
    struct stack *temp;
    temp = (struct stack*)malloc(sizeof(struct stack));
    if(*s == NULL)
    {
        printf("Stack is empty");
        return;
    }
    while(*s != NULL)
    {
        temp = *s;
        *s = (*s)->link;
        free(temp);
    }
    return;
}

int main()
{
    struct stack *s = NULL;
    int i, temp;
    for(i=3; i<=50; i+=3)
        push(&s,i);
    printf("Elements in Stack : ");
    print(&s);
    printf("\nDeleting elements : ");
    for(i=0; i<10; i++)
    {
        temp = pop(&s);
        printf("%d ",temp);
    }
    printf("\nElements in Stack : ");
    print(&s);
    printf("\nTruncating Stack");
    delete(&s);
    print(&s);
    return 0;
}
