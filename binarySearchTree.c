#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct bstNode {
	int data;
	struct bstNode* left;
	struct bstNode* right;
};
struct bstNode* insert(struct bstNode* , int);
struct bstNode* getRoot(int);
bool search(struct bstNode* ,int);
void preOrder(struct bstNode*);
void inOrder(struct bstNode*);
void postOrder(struct bstNode*);

int main() {
	struct bstNode* root = NULL;
	root = insert(root, 10);
	root = insert(root, 15);
	root = insert(root, 20);
	root = insert(root, 12);
	root = insert(root, 9);
	
	// if(search(root , 20)) {
	// 	printf("Found!!\n");
	// } else {
	// 	printf("Not found!\n");
	// }
	// preOrder(root);
	// printf("\n");
	inOrder(root);
	// printf("\n");
	// postOrder(root);
	return 0;
}
/* 
		10
	   /  \
	  9    15
	      /  \
	     12   20
	      
*/
struct bstNode* insert(struct bstNode *root, int data) {
	if(root == NULL) {
		return getRoot( data);
	}
	else if(data <= root->data) {
		root->left = insert(root->left, data);
	} else {
		root->right = insert(root->right, data);
	}
	return root;
}
struct bstNode* getRoot(int data) {
	struct bstNode *newRoot = (struct bstNode*)malloc(sizeof(struct bstNode));
	if(newRoot == NULL) {
		printf("Memory allocation failed!!");
		exit(1);
	}
	newRoot->data = data;
	newRoot->left = newRoot->right = NULL;
	return newRoot;
}
bool search(struct bstNode* root, int data) {
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if(data <= root->data) return search(root->left, data);
	else return search(root->right, data);
}
void preOrder(struct bstNode* root) {
	if(root == NULL) return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(struct bstNode* root) {
	if(root== NULL) return;
	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}
void postOrder(struct bstNode* root) {
	if(root== NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->data);
}
