#include<stdio.h>
# include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}*head = NULL;

void inserAtHead(int n)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = n;
    if(head == NULL)
    {   
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

void insertAtEnd(int n)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    struct node * temp = head;
    ptr->data = n;
    if(head == NULL)
    {   
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
     
    }
}

void insertAtAnyPosition(int n,int index)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    struct node * temp = head;
    ptr->data = n;
    for(int i=1;i<index-1;i++)
    temp = temp->next;
    ptr->next = temp->next;
    temp->next = ptr;
}

void display()
{
    struct node * temp = head;
    int i=0;
    while(temp != NULL)
    {
        if(i==0) printf("%d",temp->data);
        else printf(" -> %d",temp->data);
        i++;
        temp = temp->next;
    }
    printf(" -> NULL");
}

int main()
{
    char a;
    int i,j,k,m;
    while(a != 'a')
    {
        scanf("%c",&a);

        switch(a)
        {
            case 'b': scanf("%d",&j);inserAtHead(j);break;
            case 'c': scanf("%d",&k);insertAtEnd(k);break;
            case 'd': scanf("%d %d",&m,&i);insertAtAnyPosition(m,i);break;
            case 'a': display(); break;
        }
    }
}
