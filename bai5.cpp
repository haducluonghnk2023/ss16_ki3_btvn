#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int findMax(struct Node* node) {
    if (node == NULL) {
        return INT_MIN; 
    }

    int res = node->data;
    int lres = findMax(node->left);
    int rres = findMax(node->right);

    if (lres > res) {
        res = lres;
    }
    if (rres > res) {
        res = rres;
    }
    return res;
}

int main() {
    struct Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    printf("Gia tri lon nhat trong cay nhi phan la: %d\n", findMax(root));

    return 0;
}
