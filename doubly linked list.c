typedef struct node {
	char data[50];
	struct node* next;
	struct node* prev;
}node;

node* add(node* head) {
	char Adata[50];

	getchar();
	printf("데이터를 입력하세요 : ");
	scanf_s("%s", Adata, 20);

	if (head == NULL) {
		head = (node*)malloc(sizeof(node));
		strcpy_s(head->data, Adata);
		head->next = NULL;
		head->prev = NULL;
	}
	else {
		node* tmp;
		for (tmp = head; tmp->next != NULL; tmp = tmp->next);
		node* last = (node*)malloc(sizeof(node));
		strcpy_s(last->data, Adata);
		last->next = NULL;
		last->prev = tmp;
		tmp->next = last;

	}
	return head;
}

void show(node* head) {
	node* tmp;
	if (head == NULL)	printf("저장된 데이터가 없습니다\n");
	else
	{
		for (tmp = head; tmp != NULL; tmp = tmp->next) {
			printf("\n");
			printf(" 데이터 : %s", tmp->data);
			printf("\n");
		}
	}
}

node* insert(node* head) {
	int num1 = 0;
	int x = 0;
	show(head);
	printf("삽입할 위치를 말하세요 : ");
	scanf_s("%d", &num1);

	char Adata[50];

	getchar();
	printf("데이터를 입력하세요 : ");
	scanf_s("%s", Adata, 20);

	node* plus = (node*)malloc(sizeof(node));
	strcpy_s(plus->data, Adata);

	node* tmp;
	node* tmp1;
	if (num1 == 0) {
		plus->next = head;
		plus->prev = NULL;
		return plus;
	}
	for (tmp = head,tmp1=tmp->next; tmp != NULL; tmp = tmp->next, x++) {
		if (x == num1 - 1) {
			plus->prev = tmp;
			plus->next = tmp1;
			tmp->next = plus;
			tmp1->prev = plus;
			break;
		}
	}

	return head;
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
			//head = del(head);
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
