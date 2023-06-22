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
    else if((rear+1)%50 == front) printf("Queue overflow");
    else rear =(rear + 1)%50;
    queue[rear] = a;
}

int dequeue()
{
    if((rear == -1  && front == -1)|| front>rear) printf("Queue is empty");
    else if(front == rear)
    {
        int val = queue[front];
        front = rear = -1;
        return val;
    }
    else 
    front = (front+1)%50;
    return queue[front];
}

void display()
{
    if((rear == -1  &&  front ==-1))
    printf("Queue is empty");
    else
     {
    printf("Elements in a Queue are :");
    for(int i=front;i<=rear;i++)
    {
        printf("%d",queue[i]);
    }
    exit(0);
    }
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