#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node* result = NULL;

    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }

    return result;
}

void push(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Populate list1
    push(&list1, 9);
    push(&list1, 7);
    push(&list1, 5);

    // Populate list2
    push(&list2, 8);
    push(&list2, 6);
    push(&list2, 4);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
