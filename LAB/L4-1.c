#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char ch;
    struct node* left;
    struct node* right;
};
void push(struct node*);
struct node* pop();
struct node* createNode(char);
void infixToPrefix(char[]);
void display(struct node*);

struct node* stack[11];
int top = -1;

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }
    return 0;
}
int getPrecedence(char ch) {
    if (ch == '^') {
        return 3;
    }   
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

void main() {
    char exp[25];
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    infixToPrefix(exp);
    printf("Prefix Expression: ");
    display(pop());
}

void infixToPrefix(char exp[]) {
    int i, j = 0;
    char prefix[25];
    char temp;
    strrev(exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        }
        else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }

    for (i = 0; exp[i] != '\0'; i++) {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) {
            prefix[j++] = exp[i];
        }
        else if (exp[i] == '(') {
            struct node* newnode = createNode(exp[i]);
            push(newnode);
        }
        else if (exp[i] == ')') {
            while (top != -1 && stack[top]->ch != '(') {
                struct node* temp = pop();
                prefix[j++] = temp->ch;
            }
            if (top != -1 && stack[top]->ch == '(') {
                struct node* temp = pop();
            }
        }
        else if (isOperator(exp[i])) {
            while (top != -1 && getPrecedence(exp[i]) <= getPrecedence(stack[top]->ch)) {
                struct node* temp = pop();
                prefix[j++] = temp->ch;
            }
            struct node* newnode = createNode(exp[i]);
            push(newnode);
        }
    }
    while (top != -1) {
        struct node* temp = pop();
        prefix[j++] = temp->ch;
    }
    prefix[j] = '\0';

    strrev(prefix);
    printf("%s\n", prefix);
}

void push(struct node* ch) {
    if (top >= 10) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

struct node* pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack[top--];
}

struct node* createNode(char ch) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->ch = ch;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void display(struct node* temp) {
    if (temp == NULL) {
        return;
    }
    printf("%c", temp->ch);
    display(temp->left);
    display(temp->right);
}