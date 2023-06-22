#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
}*head = NULL;

void insertHead(int n) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = n;
    if (head == NULL) {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
    }
    else {
        ptr->next = head;
        ptr->prev = NULL;
        head->prev = ptr;
        head = ptr;
    }
}

void insertEnd(int n) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    ptr->data = n;
    ptr->next = NULL;
    if (head == NULL) {
        ptr->prev = NULL;
        head = ptr;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void delEnd() {
    if (head == NULL) {
        printf("Error! List is empty.\n");
    }
    else if (head->next == NULL) {
        head = NULL;
    }
    else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void delHead() {
    if (head == NULL) {
        printf("Error! List is empty.\n");
    }
    else {
        struct node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    }
}

void display() {
    struct node* temp = head;
    printf("Elements in the linked list:\n");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    char a;
    int b, z = 0;
    while (a != 'a' && z == 0) {
        scanf(" %c", &a);
        switch (a) {
            case 'b':
                scanf("%d", &b);
                insertHead(b);
                break;
            case 'c':
                scanf("%d", &b);
                insertEnd(b);
                break;
            case 'e':
                delHead();
                break;
            case 'f':
                delEnd();
                break;
            case 'a':
                display();
                break;
            default:
                printf("!!! ERROR !!!\n");
                z = 1;
                break;
        }
    }
    return 0;
}
