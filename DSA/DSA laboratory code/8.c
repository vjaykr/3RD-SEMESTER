#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the height of a binary tree
int height(struct Node* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Return the maximum of leftHeight and rightHeight, plus 1 for the current node
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int main() {
    // Creating a sample binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Calculate and print the height of the binary tree
    printf("Height of the binary tree is: %d\n", height(root));

    return 0;
}
