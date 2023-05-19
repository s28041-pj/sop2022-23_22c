#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void append(struct Node** headRef, int data) {
    struct Node* current;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void displayForward(struct Node* head) {
    struct Node* current = head;

    if (current == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    printf("Lista od poczatku: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


void displayBackward(struct Node* tail) {
    struct Node* current = tail;

    if (current == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    printf("Lista od konca: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}


void freeList(struct Node** headRef) {
    struct Node* current = *headRef;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }


    *headRef = NULL;
}

int main() {
    struct Node* head = NULL;
    struct Node* tail;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    displayForward(head);

    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    displayBackward(tail);

    freeList(&head);

    return 0;
}
