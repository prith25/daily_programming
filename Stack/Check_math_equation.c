/*
Check whether a given mathematical expression is valid.

    Eg.) Input  : (a+b)(a*b)
         Output : Valid

         Input  : (ab)(ab+)
         Output : Invalid

         Input  : ((a+b)
         Output : Invalid 
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct node
{
    char data;
    struct node *link;
};

void push(struct node **q, char c)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = c;
    temp->link = *q;
    *q = temp;
    return;
}

char pop(struct node **q)
{
    struct node *temp;
    if(*q == NULL)
    {
        printf("Stack is empty");
        return 'n';
    }
    char a;
    a = (*q)->data;
    temp = *q;
    *q = (*q)->link;
    free(temp);
    return a;
}

int is_alpha(char a)
{
    if((a>=65 && a<=90) || (a>=97 && a<=122))
        return 1;
    return 0;
}

int check(struct node **q)
{
    if(*q == NULL)
        return 0;
    return 1;
}

int main()
{
    struct node *s;
    s = NULL;
    char a[50] = {"(a+b)(a*b)"}, temp;
    int i;
    for(i=0; a[i]; i++)
    {
        if((a[i] == '(') || is_alpha(a[i]))
            push(&s,a[i]);
        else
        {
            if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' || a[i]=='^' || a[i]=='%')
            {
                temp = pop(&s);
                if(!((is_alpha(temp) && is_alpha(a[i+1]))))
                {
                    printf("Invalid");
                    return 0;
                }
                i = i+2;
            }
            temp = pop(&s);
            if(!(a[i]==')' && temp=='('))
            {
                printf("Invalid");
                return 0;
            }
        }
    }
    i = check(&s);
    if(i)
        printf("Invalid");
    else
        printf("Valid");
    return 0;
}

