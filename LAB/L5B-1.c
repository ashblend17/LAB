# include<stdio.h>
# include<stdlib.h>
int queue[50];
int rear = -1,front = -1;
void enqueue(int a)
{
    if(rear == -1 && front ==-1)
    {
        front = rear = 0;
    }
    else if(rear == 49) printf("Queue overflow");
    else 
    rear = rear + 1;
    queue[rear] = a;
}

int dequeue()
{
    if((rear == -1  && front == -1)|| front>rear) printf("Queue empty");
    else 
    front++;
    return queue[front];
}

void display()
{
    if((rear == -1  &&  front ==-1)|| front > rear)
    printf("Queue empty");
    else 
    printf("Front element is %d",queue[front]);
    exit(0);
}

void main()
{
    char a;
    int n;
    while(a != 'c')
    {
        scanf("%c",&a);
        switch (a)
        {
        case 'a':
            scanf("%d",&n);
            enqueue(n);
            break;
        
        case 'b':
            dequeue();
            break;

        case 'c':
            display();
            break;    
        }
    }
}