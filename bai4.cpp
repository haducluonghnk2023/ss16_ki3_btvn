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

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
       return root;
    
    if (root->data > key)
       return search(root->left, key);
 
    return search(root->right, key);
}

int main() {
    struct Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    int key = 6;
    struct Node *result = search(root, key);
    if (result != NULL) {
        printf("Gia tri %d duoc tim thay trong cay\n", key);
    } else {
        printf("Gia tri %d khong duoc tim thay trong cay\n", key);
    }

    return 0;
}
