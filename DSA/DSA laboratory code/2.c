#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

void push_stack(int data) {
    top = top + 1;
    stack[top] = data;
}

void pop_stack() {
    top = top - 1;
}

struct Interval {
    int start;
    int end;
};

int main() {
    int i, n;
    struct Interval array[] = { {1, 3}, {2,6}, {8,10}, {15,18} };

    int size = sizeof(array) / sizeof(array[0]);
    n = size;

    for (i = 0; i < n; i++) {
        if (top == -1) {
            push_stack(array[i].start);
            push_stack(array[i].end);
        }
        else if (top != -1) {
            if (array[i].start <= stack[top]) {
                pop_stack();
                push_stack(array[i].end);
            }
            else {
                push_stack(-1); // Push a sentinel value to indicate a closing brace
                push_stack(array[i].start);
                push_stack(array[i].end);
            }
        }
    }

    printf("{ ");
    for (i = 0; i <= top; i++) {
        if (stack[i] == -1) {
            printf(" } { ");
        }
        else {
            printf("%d ", stack[i]);
        }
    }
    printf("}\n");

    return 0;
}