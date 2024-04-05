#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

bool arePairs(char opening, char closing) {
    if (opening == '(' && closing == ')') {
        return true;
    } else if (opening == '[' && closing == ']') {
        return true;
    } else if (opening == '{' && closing == '}') {
        return true;
    } else {
        return false;
    }
}

bool isBalanced(char A[]) {
    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; A[i] != '\0'; i++)
        {
          if (A[i] == '[' || A[i] == '{' || A[i] == '(')
             {
                stack[++top] = A[i];
             }
          else if (A[i] == ']' || A[i] == '}' || A[i] == ')')
            {
            if (top == -1 || ! arePairs(stack[top], A[i])) {
                return false;
            }
            else
            {
                top--;
            }
        }
    }

    return top == -1;
}

int main() {
    char exp[100];
    printf("enter the expression:\n");
    scanf("%s",exp);
  //  char expression[] = "[{[]}]";

    if (isBalanced(exp)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }
    return 0;
}