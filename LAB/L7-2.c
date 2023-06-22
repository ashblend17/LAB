#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}*head = NULL;

void insertHead(int n)
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

void insertEnd(int n)
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

void insertAnyPosition(int n,int index)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    struct node * temp = head;
    ptr->data = n;
    for(int i=1;i<index-1;i++)
    temp = temp->next;
    ptr->next = temp->next;
    temp->next = ptr;
}

void deleteAnyposition(int index)
{
    struct node * temp1 = head;
    struct node * temp2 = head;
    if(head == NULL) printf("Overflow condition of Linked list");
    else
    {
        for(int i=1;i<index-1;i++)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp2 = temp2->next;
        temp1->next = temp2->next;
    }
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
            case 'b': scanf("%d",&j);insertHead(j);break;
            case 'c': scanf("%d",&k);insertEnd(k);break;
            // case 'd': scanf("%d %d",&m,&i);insertAnyPosition(m,i);break;d
            case 'd': scanf("%d",&i);deleteAnyposition(i);break;
            case 'a': display(); break;
        }
    }
}
