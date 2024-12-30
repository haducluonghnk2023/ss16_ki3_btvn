#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	Node* right;
	Node* left;
} Node;
Node* createNode(int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
void preOrder(Node* root){
	if(root == NULL){
		return;
	}
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Node* root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}
void postOrder(Node* root){
	if(root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->data);
}
int main(){
	Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
	return 0;
}

