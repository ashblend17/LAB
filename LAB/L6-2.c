#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insFirst(int num) {
    struct Node* ins = (struct Node*)malloc(sizeof(struct Node));
    if (ins == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    ins->data = num;
    ins->next = head;
    head = ins;
}

void insLast(int num) {
    struct Node* a = (struct Node*)malloc(sizeof(struct Node));
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    a->data = num;
    a->next = NULL;

    if (head == NULL) {
        head = a;
        return;
    }

    struct Node* b = head;
    while (b->next != NULL) {
        b = b->next;
    }
    b->next = a;
}

void display() {
    struct Node* a = head;
    if (a == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Elements in the linked list:\n");
    while (a != NULL) {
        printf("%d", a->data);
        if (a->next != NULL) {
            printf(" -> ");
        }
        a = a->next;
    }
    printf("\n");
}

void deleteFirst() {
    if (head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteLast() {
    if (head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }

    struct Node* aa = head;
    struct Node* bb = head->next;

    if (bb == NULL) {
        free(aa);
        head = NULL;
        return;
    }

    while (bb->next != NULL) {
        aa = aa->next;
        bb = bb->next;
    }

    aa->next = NULL;
    free(bb);
}

int main(void) {
    char c = 'y';
    while (c == 'y') {
        char cc;
        scanf(" %c", &cc);
        switch (cc) {
            case 'b': {
                int num;
                scanf("%d", &num);
                insFirst(num);
                break;
            }
            case 'c': {
                int num;
                scanf("%d", &num);
                insLast(num);
                break;
            }
            case 'e':
                deleteFirst();
                break;
            case 'f':
                deleteLast();
                break;
            case 'a':
                display();
                c = 'n';
                break;
            default:
                printf("Invalid input\n");
                c = 'n';
                break;
        }
    }
    return 0;
}
