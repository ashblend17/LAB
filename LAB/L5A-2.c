#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct 
{
    int data[100];
    int top;
} Stack;
void push(Stack *stack, int item) 
{
    if (stack->top >= 100 - 1)
     {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(1);
    }
    stack->top++;
    stack->data[stack->top] = item;
}

int pop(Stack *stack) 
{
    if (stack->top < 0) 
    {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(1);
    }
    int item = stack->data[stack->top];
    stack->top--;
    return item;
}

int evaluate_postfix(char postfix[])
 {
    Stack operand_stack = { .top = -1 };
    int i;
    char ch;
    int operand1, operand2;

    for (i = 0; postfix[i] != '\0'; i++) 
    {
        ch = postfix[i];

        if (isdigit(ch)) {
            push(&operand_stack, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
        {
            operand2 = pop(&operand_stack);
            operand1 = pop(&operand_stack);

            switch (ch) 
            {
                case '+':
                    push(&operand_stack, operand1 + operand2);
                    break;
                case '-':
                    push(&operand_stack, operand1 - operand2);
                    break;
                case '*':
                    push(&operand_stack, operand1 * operand2);
                    break;
                case '/':
                    push(&operand_stack, operand1 / operand2);
                    break;
                default:
                    fprintf(stderr, "Error: Invalid operator %c\n", ch);
                    exit(1);
            }
        }
    }

    return pop(&operand_stack);
}

int main() 
{
    char postfix[100];
    scanf("%s",postfix);

    int result = evaluate_postfix(postfix);

    printf("The result is: %d\n", result);

    return 0;
}