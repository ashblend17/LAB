#include<stdio.h>
# include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertAtHead(int n)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = n;
    if(head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

void insertAtEnd(int n)
{
    // struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    // ptr = head;
    // while(ptr != NULL) ptr = ptr->next;
    // ptr->data = n;
    // ptr->next =NULL;

    struct node * ptr = (struct node *)malloc(sizeof(struct node *));
    struct node * temp = head;

    if(head == NULL)
    {
        head = ptr;
        ptr->data = n;
        ptr->next = NULL;
    }
    else 
    {
        while(temp->next != NULL)
        temp = temp->next;
        temp->next = ptr;
        ptr->data = n;
        ptr->next = NULL;
    }
    
}

void display()
{
    struct node * ptr;
    ptr = head;
    int i=0;
    printf("Elements in the linked List :\n");
    while(ptr != NULL)
    {
        if(i != 0)
        {
            printf(" -> %d",ptr->data);
        }
        else printf("%d",ptr->data);

        ptr = ptr->next;
        i++;
    }
}

int main()
{
    char a;
    int j,k;
    
    while(a != 'a')
    {
        scanf("%c",&a);
        
        switch(a)
        {
            case 'a': display(); break;
            case 'b': scanf("%d",&j);insertAtHead(j); break;
            case 'c': scanf("%d",&k);insertAtEnd(k); break;
        }

    }

    return 0;
}