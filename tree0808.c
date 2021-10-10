#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* lchild;
	node* rchild;
}node;

node* addnode(node* A,int data) {
	if (A != NULL) {
		if (A->data > data) {
			A->lchild = addnode(A->lchild, data);
		}
		else if (A->data < data) {
			A->rchild = addnode(A->rchild, data);
		}
		else printf("중복\n");
	}
	else {
		node* tmp = (node*)malloc(sizeof(node));
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

node* insert(node* A, int data, int loc) {

	while (A) {
		if (A->data == loc) {
			break;
		}
		else if (A->data > loc) {
			A = A->lchild;
		}
		else {
			A = A->rchild;
		}
	}
	if (A == NULL) {
		printf("failed inserting..");
		return A;
	}
	node* ltmp = A->lchild;
	node* rtmp = A->rchild;
	A->lchild = NULL;
	A->rchild = NULL;

	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;

	if (A->data > data) {
		A->lchild = tmp;
		A = A->lchild;
	}
	else {
		A->rchild = tmp;
		A = A->rchild;
	}
	A->lchild = (ltmp!=NULL? ltmp:NULL);
	A->rchild = (rtmp != NULL ? rtmp : NULL);
	
	return A;
}

node* delete_tree(node* A, int data) {
	if (A == NULL) return A;
	if (data < A->data) {
		A->lchild = delete_tree(A->lchild, data);
	}
	else if (data > A->data) {

	}
	else {
		if (A->rchild == NULL) {

		}
		else if (A->rchild == NULL) {

		}

		

	}

	return A;
}

int main() {
	node* root = NULL;
	int data = 0;
	int num = 0;
	int loc = 0;
	int arr[3] = {0};

	printf("3개의 데이터를 입력하세요 : ");
	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &data);
		arr[i] = data;
	}
	
	for (int i = 0; i < 3; i++) {
		root = addnode(root, arr[i]);
	}
	while (1) {

		printf("===================================\n");
		printf(" 1. 삽입\n");
		printf(" 2. 삭제\n");
		printf(" 3. inorder\n");
		printf(" 4. preorder\n");
		printf(" 5. postorder\n");
		printf("===================================\n");

		printf("번호를 선택하세요 : ");
		scanf_s("%d", &num);


		switch (num) {
		case 1:
			printf("삽입할 위치의 데이터를 입력하세요 : ");
			scanf_s("%d", &loc);
			printf("데이터를 입력하세요 : ");
			scanf_s("%d", &data);
			insert(root, data, loc);
			break;
		case 2:
			break;
		case 3:
			printf("\ninorder : ");
			inorder(root);
			printf("\n");
			break;
		case 4:
			printf("\npreorder : ");
			preorder(root);
			printf("\n");
			break;
		case 5:
			printf("\npostorder : ");
			postorder(root);
			printf("\n");
			break;
		default:
			return 0;
		}
	}

}
