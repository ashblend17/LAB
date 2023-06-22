#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char data[100];
    int top;
} Stack;

void push(Stack *stack, char item)
{
    if (stack->top >= 100 - 1)
    {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(1);
    }
    stack->top++;
    stack->data[stack->top] = item;
}

char pop(Stack *stack) 
{
    if (stack->top < 0) 
    {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(1);
    }
    char item = stack->data[stack->top];
    stack->top--;
    return item;
}

int is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return 1;
    } else {
        return 0;
    }
}

int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infix_to_postfix(char infix[], char postfix[])
{
    Stack operator_stack = { .top = -1 };
    int i, j;
    char ch;

    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isdigit(ch) || isalpha(ch))
        {
            postfix[j] = ch;
            j++;
        } else if (ch == '(')
        {
            push(&operator_stack, ch);
        } else if (ch == ')')
        {
            while (operator_stack.data[operator_stack.top] != '(')
            {
                postfix[j] = pop(&operator_stack);
                j++;
            }
            pop(&operator_stack);
        } else if (is_operator(ch))
        {
            while (operator_stack.top >= 0 && precedence(ch) <= precedence(operator_stack.data[operator_stack.top]))
            {
                postfix[j] = pop(&operator_stack);
                j++;
            }
            push(&operator_stack, ch);
        }
    }

    while (operator_stack.top >= 0)
    {
        postfix[j] = pop(&operator_stack);
        j++;
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100];
    char postfix[100] = "";
    scanf("%s",infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;
}
