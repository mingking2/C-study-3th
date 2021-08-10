// TREE는 비선형구조
// 2진 트리 -> 나 밑에는 무조건 2개씩 존재, 2개중에 왼쪽은 나보다 작은 것, 오른쪽은 나보다 큰 것으로 저장

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node {
	int data;
	node* lchild;
	node* rchild;
}node;

node* newnode(node* p, int data) {
	if (p != NULL) {
		if (p->data > data) {
			p->lchild = newnode(p->lchild, data);
		}
		else if (p->data < data) {
			p->rchild = newnode(p->rchild, data);
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
	return p;
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

node* findparent(node* p) {
	node* tmp = NULL;
	while (p) {
		tmp = p;
		p = p->lchild;
	}
	return tmp;
}
node* deltree(node* A, int data) {
	node* tmp = NULL;
	if (A) {
		if (A->data > data)
			A->lchild = deltree(A->lchild, data);
		else if (A->data < data)
			A->rchild = deltree(A->rchild, data);
		else {
			//found data
			if (A->rchild && A->lchild) {		// 자식이 둘다 잇을때
				tmp = findparent(A->rchild);	// 오른쪽가서 왼쪽 쭈우우우욲
				A->data = tmp->data;		// 데이터를 옮김
				A->rchild = deltree(A->rchild, tmp->data);		// 옮기기전 위치에 잇던 데이터 삭제

			}
			else {
				//한쪽만 살아있을때+없으면 null 넣어주니 굿
				tmp = (A->lchild ? A->lchild : A->rchild);
				free(A);
				return tmp;
			}
		}
	}
	return A;
}

int count = 0;

//void leafnode(node* p) {
//	if(p->lchild!=NULL)	leafnode(p->lchild);
//	if(p->rchild!=NULL)	leafnode(p->rchild);
//
//	if (p->lchild == NULL && p->rchild == NULL) count++;
//}

int leafnode(node* ptr) {
	if (ptr)
		//00이면 1 반환
		if ((ptr->lchild) == NULL && (ptr->rchild) == NULL)
			return 1;
		else
			return leafnode(ptr->lchild) + leafnode(ptr->rchild);
	//한쪽만 널 일경우
	else
		return 0;
}


int max = 0;

//void maxlevel(node* p,int nowlevel) {
//	if (p->lchild == NULL && p->rchild == NULL) {
//		if (nowlevel > max) max = nowlevel;
//		return;
//	}
//	if (p->lchild != NULL)	maxlevel(p->lchild,nowlevel+1);
//	if (p->rchild != NULL)	maxlevel(p->rchild,nowlevel+1);
//}
int maxlevel(node* ptr) {
	int cr, cl;
	if (ptr)
		if ((ptr->lchild) == NULL && (ptr->rchild) == NULL)
			return 1;
		else {
			cl = maxlevel(ptr->lchild);
			cr = maxlevel(ptr->rchild);
			return cl > cr ? cl + 1 : cr + 1;
		}
	else
		return 0;
}


int main() {
	srand((unsigned int)time(NULL));
	node* root = NULL;
	int data = 0;
	int num = 0;
	

	for (int i = 0; i < 10; i++) {
		int s = rand() % 30 + 1;
		root = newnode(root, s);
		printf("%d ", s);
	}
	printf("\n");
	while (1) {

		printf("===================================\n");
		printf(" 1. inorder\n");
		printf(" 2. preorder\n");
		printf(" 3. postorder\n");
		printf(" 4. 삭제\n");
		printf(" 5. leafnode의 개수\n");
		printf(" 6. maxlevel\n");
		printf("===================================\n");

		printf("번호를 선택하세요 : ");
		scanf_s("%d", &num);


		switch (num) {
		case 1:
			printf("\ninorder : ");
			inorder(root);
			printf("\n");
			break;
		case 2:
			printf("\npreorder : ");
			preorder(root);
			printf("\n");
			break;
		case 3:
			printf("\npostorder : ");
			postorder(root);
			printf("\n");
			break;
		case 4:
			printf("삭제할 데이터를 입력하세요 : ");
			scanf_s("%d", &data);
			root = deltree(root, data);
			break;
		case 5:
			count = 0;
			printf("\nleafnode의 개수 : %d\n", leafnode(root));
			break;
		case 6:
			max = 0;
			printf("\nmaxlevel : %d\n", maxlevel(root));
		default:
			return 0;
		}
	}
}
