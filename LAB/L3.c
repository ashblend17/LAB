# include<stdio.h>
# include<stdlib.h>

int a[20],top = -1;
int isFull()
{
    if(top == 19) return 1;
    else return 0;
}
int isEmpty()
{
    if(top == -1) return 1;
    else return 0;
}
void push(int b)
{
    if(isFull()) printf("Stack overflow");
    else 
    {
        top++;
        a[top] = b;
    }
}
void display()
{
    if(isEmpty()) printf("Stack empty");
    else printf("Top Element is %d",a[top]);
    exit(0);
}
int pop()
{
    if(isEmpty())
    {
        display();
        return 0;
    }
    else 
    {
        top--;
        return a[top+1];
    }
}
int main()
{
    char c;
    int i;
    do
    {
        scanf("%c",&c);
        if(c == 'c')
        {
            display();
        }
        else scanf("%d",&i);
        switch(c)
        {
            case 'a': push(i); break;
            case 'b': pop(); break;
        }
    }
    while(c != 'c');
}