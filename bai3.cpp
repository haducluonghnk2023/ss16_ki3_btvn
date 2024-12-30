#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int countLeaves(struct Node* node) {
    if (node == NULL) {
        return 0; 
    }
    if (node->left == NULL && node->right == NULL) {
        return 1; 
    } else {
        return countLeaves(node->left) + countLeaves(node->right);
    }
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("So luong la trong cay nhi phan la %d\n", countLeaves(root));

    return 0;
}
