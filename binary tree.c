#include <stdio.h>
#include <stdlib.h>
//2진 tree
// 순회방법 
//pre-order : 나 -> 왼 -> 오
//in-order : 왼 -> 나 -> 오
//post order : 왼 -> 오 -> 나

typedef struct node {
	int data;
	node* Lnode;
	node* Rnode;
}node;

node* newnode(int data) {
	
	node* newnode = (node*)malloc(sizeof(node));
	newnode->Lnode = NULL;
	newnode->Rnode = NULL;

	return newnode;
}

node* add(node* tmp,int data) {
	
	if (tmp == NULL) {
		tmp = newnode(data);
		return tmp;
	}
	
	if (tmp->data>data && tmp->Lnode==NULL) {
		tmp->Lnode = newnode(data);
		return tmp;
	}
	else if (tmp->data <= data && tmp->Rnode == NULL) {
		tmp->Rnode = newnode(data);
		return tmp;
	}
	if (tmp->data > data) add(tmp->Lnode, data);
	else add(tmp->Rnode, data);

}

void show(node* tmp) {
	if (tmp== NULL) return;
	else {
		printf("%d \n", tmp->data);
		show(tmp->Lnode);
		show(tmp->Rnode);
	}
}

int main() {
	int num = 0;
	int data;
	node* head = NULL;
	while (1) {

		printf("===============================\n");
		printf("  1. 추가\n");
		printf("  2. 조회\n");
		printf("===============================\n");
		printf(" 번호를 입력하세요 : ");
		scanf_s("%d", &num);


		switch (num) {
		case 1:
			getchar();
			printf("데이터 : ");
			scanf_s("%d", &data);

			head = add(head,data);
			break;
		case 2:
			show(head);
			break;
		}


	}
}
