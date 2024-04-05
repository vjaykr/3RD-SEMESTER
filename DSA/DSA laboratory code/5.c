#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largest_rectangle_area(int heights[], int n) {
    int stack[n];
    int top = -1;
    int max_area = 0;
    int i = 0;

    while (i < n) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i;
            i++;
        }
        else {
            int top_of_stack = stack[top--];
            int area = heights[top_of_stack] * (top == -1 ? i : i - stack[top] - 1);
            max_area = MAX(max_area, area);
        }
    }

    while (top != -1) {
        int top_of_stack = stack[top--];
        int area = heights[top_of_stack] * (top == -1 ? i : i - stack[top] - 1);
        max_area = MAX(max_area, area);
    }

    return max_area;
}

int main() {
    int histogram[] = {2, 1, 5, 6, 2, 3};
    int size = sizeof(histogram) / sizeof(histogram[0]);
    int area = largest_rectangle_area(histogram, size);
    printf("Largest rectangle area: %d\n", area);  // Output: 10

    return 0;
}