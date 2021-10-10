#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node {
	int data;
	node* lchild;
	node* rchild;
}node;

node* addnode(node* A, int data){
	if (A!=NULL) {
		if (A->data > data)	A->lchild = addnode(A->lchild, data);
		 else if (A->data < data) A->rchild = addnode(A->rchild, data);
		else { 
			printf("중복\n"); 
		}
	}
	else {
		node*tmp = (node*)malloc(sizeof(node));
		tmp->data = data;
		tmp->lchild = NULL;
		tmp->rchild = NULL;
		return tmp;
	}
	
	return A;
}

void inorder(node* p) {
	if (p) {
		inorder(p->lchild);
		printf("%d ", p->data);
		inorder(p->rchild);
	}
}

void preorder(node* p) {
	if (p) {
		printf("%d ", p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void postorder(node* p) {
	if (p) {
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d ", p->data);
	}
}


int main() {
	node* root = NULL;

	// 편향 트리 여서 inorder랑 preorder 같음ㅇㅇ




	int arr[10] = { 2,4,6,8,10,1,3,5,7,9 };
	for (int i = 0; i < 10; i++) {
		root = addnode(root, arr[i]);
	}
	printf("\ninorder : ");
	inorder(root);
	printf("\npreorder : ");
	preorder(root);
	printf("\npostorder : ");
	postorder(root);


}


