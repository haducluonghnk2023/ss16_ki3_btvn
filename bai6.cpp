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

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node->data) {
        node->left  = insert(node->left, data);
    } 
    else if (data > node->data) {
        node->right = insert(node->right, data);  
    }

    return node;
}

int countNodesGreaterThanX(struct Node* node, int X) {
    if (node == NULL) {
        return 0;
    }

    int count = 0;
    if (node->data > X) {
        count = 1;
    }

    count += countNodesGreaterThanX(node->left, X);
    count += countNodesGreaterThanX(node->right, X);

    return count;
}

int main() {
    struct Node *root = NULL;
    int X, data, n, i;

    printf("Nhap gia tri X: ");
    scanf("%d", &X);

    printf("Nhap so luong node muon chen: ");
    scanf("%d", &n);

    printf("Nhap gia tri cac node: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    int count = countNodesGreaterThanX(root, X);
    printf("So luong node co gia tri lon hon %d la: %d\n", X, count);

    return 0;
}
