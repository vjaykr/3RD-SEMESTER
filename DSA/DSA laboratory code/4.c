#include <stdio.h>

void findNextGreaterElement(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int nextGreater = -1;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nextGreater = arr[j];
                break;
            }
        }

        printf("%d --> %d\n", arr[i], nextGreater);
    }
}

int main() {
    int arr[] = {4, 5, 2, 25, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    findNextGreaterElement(arr, n);

    return 0;
}