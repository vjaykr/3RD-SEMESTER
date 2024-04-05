#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to check if a binary tree is a BST
bool isBST(struct TreeNode* root, struct TreeNode* left, struct TreeNode* right) {
    if (root == NULL)
        return true;

    if (left != NULL && root->data <= left->data)
        return false;

    if (right != NULL && root->data >= right->data)
        return false;

    return isBST(root->left, left, root) && isBST(root->right, root, right);
}

int main() {
    // Create your binary tree here
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = 4;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->data = 6;
    // ... continue building your tree

    if (isBST(root, NULL, NULL))
        printf("The given tree is a Binary Search Tree.\n");
    else
        printf("The given tree is not a Binary Search Tree.\n");

    return 0;
}
