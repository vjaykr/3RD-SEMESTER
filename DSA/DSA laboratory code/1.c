#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int findNextGreater(int num) {
    // Convert the number to a string
    char strNum[20];
    sprintf(strNum, "%d", num);
    int len = strlen(strNum);

    // Find the first digit smaller than the digit on its right
    int i;
    for (i = len - 2; i >= 0; i--) {
        if (strNum[i] < strNum[i + 1])
            break;
    }

    // If no such digit found, return -1
    if (i == -1)
        return -1;

    // Find the smallest digit on the right side of the digit found earlier
    int smallestDigitIndex = i + 1;
    for (int j = i + 2; j < len; j++) {
        if (strNum[j] < strNum[smallestDigitIndex] && strNum[j] > strNum[i])
            smallestDigitIndex = j;
    }

    // Swap the two digits
    swap(&strNum[i], &strNum[smallestDigitIndex]);

    // Sort the digits on the right side of the swapped digit in ascending order
    for (int j = i + 1; j < len - 1; j++) {
        for (int k = j + 1; k < len; k++) {
            if (strNum[j] > strNum[k])
                swap(&strNum[j], &strNum[k]);
        }
    }

    // Convert the modified string back to an integer
    int nextGreater = atoi(strNum);
    return nextGreater;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int nextGreater = findNextGreater(num);
    if (nextGreater != -1)
        printf("The smallest number greater than %d with the same set of digits is %d.\n", num, nextGreater);
    else
        printf("No greater number with the same set of digits exists.\n");

    return 0;
}