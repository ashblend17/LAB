#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
    }
}
void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
        printf("Elements in the linked list:\n");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void deleteFromBeginning() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    struct Node* toDelete = head;
    head = head->next;
    temp->next = head;
    free(toDelete);
}
void deleteFromEnd() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
        prev->next = head;
    else
        head = NULL;
    free(temp);
}
int main() {
    int choice, data;
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                display();
                exit(0);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                display();
                break;
            default:
                printf("Error!!!\n");
        }
    }

    return 0;
}