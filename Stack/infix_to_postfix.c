/*

Infix to Postfix conversation:
******************************

1. Print operands as they arrive.

2. If the stack is empty or contains a left parenthesis on top, 
push the incoming operator onto the stack.

3. If incoming symbol is '(', push it onto the stack.

4. If incoming symbol is ')', pop the stack & print the operators until left 
parenthesis is found.

5. If incoming symbol has higher precedence than the top of the stack, 
then push it onto the stack.

6. If incoming symbol has lower precedence than the top of the stack,
pop & print the top. Then test the incoming operator against the new top
of the stack.

7. If the incoming operator has equal precedence with the top of the stack,
use associativity rule.

8. If incoming symbol is a operator and top of the stack is '(', then just add
the operator into the stack without any associativity rule.

9. At the end of the expression, pop & print all operators of the stack.

Priority of operator:
****************

1. Parenthesis
2. Exponential(right -> left)
3. Multiplication and division (Left -> right)
4. Addition and Subtraction (left -> right)

Associativity:
**************

1. Left to Right:
*****************
Pop & print the top of the stack and then push the incoming operator.

2. Right to Left:
*****************
Push the incoming operator.

*/

#include <stdio.h>
#include <malloc.h>

struct stack
{
    char data;
    struct stack *link;
};

int operator_priority(char op)
{
    if(op == '(' || op == ')')
        return 1;
    else if(op == '^')
        return 2;
    else if(op == '*' || op == '/')
        return 3;
    else
    {
        if(op == '+' || op == '-')
            return 4;
    }
}

char check_associativity(char op)
{
    if(op == '^')
        return 'R';
    else if(op == '+' || op == '-')
        return 'L';
    else
    {
        if(op == '*' || op == '/')
            return 'L';
    }
}

void push(struct stack **top, char alpha)
{
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = alpha;
    temp->link = *top;
    *top = temp;
    return;
}

char pop(struct stack **top)
{
    struct stack *temp;
    temp = (struct stack*)malloc(sizeof(struct stack));
    if(*top == NULL)
        return '!';
    char alpha;
    alpha = (*top)->data;
    temp = *top;
    *top = (*top)->link;
    free(temp);
    return alpha;
}

int is_operands(char a)
{
    if((a>=48 && a<=57) || (a>=97 && a<=122))
        return 1;
    return 0;
}

int is_operator(char a)
{
    if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^')
        return 1;
    return 0;
}

int main()
{
    struct stack *s;
    s = NULL;
    char expression[100] = {"a+b*(c^d-e)^(f+g*h)-i"}, top_element, postfix[100], temp;
    int i, z, len;
    printf("Enter the expression: ");
    //scanf("%s",expression);
    printf("%s",expression);
    for(len=0; expression[len]; len++);
    for(i=0,z=0; i<len; i++)
    {
        if(is_operands(expression[i]))
            postfix[z++] = expression[i];
            
        else if(is_operator(expression[i]) && s==NULL)
        {
            push(&s,expression[i]);
            top_element = expression[i];
        }
        
        else if(is_operator(expression[i]) && top_element=='(')
        {
            push(&s,expression[i]);
            top_element = expression[i];
        }
        
        else if(expression[i] == '(')
        {
            push(&s,expression[i]);
            top_element = expression[i];
        }
        
        else if(expression[i] == ')')
        {
            temp = pop(&s);
            while(temp != '(')
            {
                postfix[z++] = temp;
                temp = pop(&s);
            }
            top_element = pop(&s);
            push(&s,top_element);
        }
        
        else if((operator_priority(expression[i])) < (operator_priority(top_element)))
        {
            push(&s,expression[i]);
            top_element = expression[i];
        }
        
        else if((operator_priority(expression[i])) > (operator_priority(top_element)))
        {
            temp = pop(&s);
            postfix[z++] = temp;
            top_element = pop(&s);
            push(&s,top_element);
            i--;
        }
        
        else
        {
            if((operator_priority(expression[i])) == (operator_priority(top_element)))
            {
                temp = check_associativity(expression[i]);
                if(temp == 'L')
                {
                    temp = pop(&s);
                    postfix[z++] = temp;
                    push(&s,expression[i]);
                    top_element = expression[i];
                }
                else
                {
                    push(&s,expression[i]);
                    top_element = expression[i];
                }
            }
        }
    }
    temp = pop(&s);
    while(temp != '!')
    {
        postfix[z++] = temp;
        temp = pop(&s);
    }
    postfix[z] = '\0';
    printf("\nPostfix expression : %s",postfix);
    return 0;
}
