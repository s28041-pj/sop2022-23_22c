#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** headRef, int data) {
    struct Node* current;

    if (*headRef == NULL) {
        *headRef = (struct Node*)malloc(sizeof(struct Node));
        (*headRef)->data = data;
        (*headRef)->next = NULL;
        return;
    }

    current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (struct Node*)malloc(sizeof(struct Node));
    current->next->data = data;
    current->next->next = NULL;
}

void display(struct Node* head) {
    struct Node* current = head;

    if (current == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    printf("Lista: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
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

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    display(head);

    freeList(&head);

    return 0;
}
