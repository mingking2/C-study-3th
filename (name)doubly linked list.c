#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char name[50];
	struct node* next;
	struct node* prev;
}node;

node* add(node* head) {
	char Aname[100];

	getchar();
	printf("이름 : ");
	scanf_s("%s", Aname, 50);

	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
		strcpy_s(head->name, Aname);
		head->next = NULL;
		head->prev = NULL;
	}
	else {
		node* tmp;
		for (tmp = head; tmp->next != NULL; tmp = tmp->next);
		node* last = (node*)malloc(sizeof(node));
		strcpy_s(last->name, Aname);
		last->next = NULL;
		last->prev = tmp;
		tmp->next = last;
	}

	return head;
}

node* del(node* head) {
	
	char word[50];
	printf("삭제하고 싶은 이름 입력 : ");
	scanf_s("%s", word, 20);

	node* tmp;

	for (tmp = head;tmp!=NULL; tmp = tmp->next) {
		if (strcmp(tmp->name, word) == 0) {
			if (head->next == NULL) {
				free(head);
				return 0;
			}
			node* f = tmp->prev;
			node* b = tmp->next;
			
			if (tmp->prev == NULL) {
				b->prev = NULL;
				head = b;
				break;
			}
			else if (tmp->next == NULL) {
				node* deltmp = tmp;
				tmp = tmp->prev;
				tmp->next = NULL;
				deltmp->prev = NULL;
				free(deltmp);
			}
			else {
				b->prev = f;
				f->next = b;
				break;
			}
			break;
		}
		
	}
	return head;
}

void show(node* head) {
	node* tmp;
	if (head == NULL)	printf("저장된 이름이 없어여\n");
	else{
		for (tmp=head; tmp != NULL; tmp = tmp->next) {
			printf("\n");
			printf("이름 : %s",tmp->name);
			printf("\n");

		}
	}

}

node* insert(node* head) {
	int num1 = 0;
	int x = 0;
	if (head != NULL) {
		show(head);
		printf("삽입할 위치를 입력하세요 : ");
		scanf_s("%d", &num1);

		char Aname[100];

		getchar();
		printf("데이터를 입력하세요 : ");
		scanf_s("%s", Aname, 50);

		node* plus = (node*)malloc(sizeof(node));
		strcpy_s(plus->name, Aname);
		plus->next = NULL;
		plus->prev = NULL;

		node* Ltmp;
		node* Rtmp;
		if (num1 == 0) {
			plus->next = head;
			plus->prev = NULL;
			return plus;
		}

		for (Ltmp = head, Rtmp = Ltmp->next; Ltmp != NULL; Ltmp = Ltmp->next, Rtmp = Rtmp->next, x++) {

			if (x == num1 - 1) {
				plus->next = Rtmp;
				plus->prev = Ltmp;
				Ltmp->next = plus;
				if (Rtmp != NULL)	Rtmp->prev = plus;
				break;
			}
		}

		printf("%d", x);

		return head;
	}
	else printf("저장된 데이터가 없어여\n");
}

int main() {
	int num = 0;
	node* head = NULL;

	while (1) {

		printf("===============================\n");
		printf("  1. 추가\n");
		printf("  2. 삭제\n");
		printf("  3. 조회\n");
		printf("  4. 삽입\n");
		printf("===============================\n");
		printf(" 번호를 입력하세요 : ");
		scanf_s("%d", &num);


		switch (num) {
		case 1:
			head = add(head);
			break;
		case 2:
			head = del(head);
			break;
		case 3:
			show(head);
			break;
		case 4:
			head = insert(head);
			break;
		}


	}
}
