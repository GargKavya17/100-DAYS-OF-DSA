// Problem: BST Search
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL && root->val != val) {
        root = (val < root->val) ? root->left : root->right;
    }
    return root;
}
int main() {
   
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int target = 2;
    struct TreeNode* result = searchBST(root, target);

    if (result != NULL) {
        printf("Node found! Value: %d\n", result->val);
        if (result->left) printf("Left child: %d\n", result->left->val);
        if (result->right) printf("Right child: %d\n", result->right->val);
    } else {
        printf("Node with value %d not found.\n", target);
    }

    return 0;
}