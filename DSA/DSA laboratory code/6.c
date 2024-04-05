#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int getNthFromEnd(Node* head, int n) {
    if (head == NULL || n <= 0) {
        printf("Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    Node* fast = head;
    Node* slow = head;

    // Move the fast pointer n positions ahead
    int count = 0;
    while (count < n) {
        if (fast == NULL) {
            printf("The list does not have %d nodes.\n", n);
            exit(EXIT_FAILURE);
        }
        fast = fast->next;
        count++;
    }

    // Move both pointers until the fast pointer reaches the end
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int n, value;

    // Insert nodes into the linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Get the value at the Nth node from the end
    n = 3;
    int result = getNthFromEnd(head, n);
    printf("Value at the %dth node from the end: %d\n", n, result);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}