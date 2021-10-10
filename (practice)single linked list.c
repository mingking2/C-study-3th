#include <stdio.h>
#include <stdlib.h>

struct Bitcoin {
	int cash;
	char alpha;
	Bitcoin* next;
}typedef Bitcoin;

Bitcoin* add(Bitcoin* head) {
	char Aalpha;
	int Acash;

	getchar();
	printf("알파벳을 입력하세요 : ");
	scanf_s("%c", &Aalpha);
	printf("돈을 입력하세요 : ");
	scanf_s("%d", &Acash);

	if (head == NULL) {
		head = (Bitcoin*)malloc(sizeof(Bitcoin));
		head->alpha = Aalpha;
		head->cash = Acash;
		head->next = NULL;
	}
	else {
		Bitcoin* tmp;		//마지막에 찾는거	
		for (tmp = head; tmp->next != NULL; tmp = tmp->next);
		Bitcoin* coin = (Bitcoin*)malloc(sizeof(Bitcoin));		// coin은 맨 뒤에 붙음
		coin->alpha = Aalpha;
		coin->cash = Acash;
		coin->next = NULL;
		tmp->next = coin;
	}

	return head;
}

Bitcoin* del(Bitcoin* head) {
	Bitcoin* tmp;

	if (head == NULL)	printf("지울 데이터가 없습니다.\n");
	else if (head->next == NULL) {
		tmp = head;
		head = NULL;
		free(tmp);
	}
	else {
		for (tmp = head; tmp->next->next != NULL; tmp = tmp->next);
		Bitcoin* deltmp = tmp->next;
		tmp->next = NULL;
		free(deltmp);
	}

	return head;

}

void show(Bitcoin* head) {
	Bitcoin* tmp;
	if (head == NULL)	printf("저장된 데이터가 없습니다\n");
	else
	{
		for (tmp = head; tmp != NULL; tmp = tmp->next) {
			printf("\n");
			printf(" 이름 : %c", tmp->alpha);
			printf(" 돈 : %d", tmp->cash);
			printf("\n");
		}
	}
}

Bitcoin* insert(Bitcoin* head) {
	int num1;
	int x = 0;
	show(head);
	printf("삽입할 위치를 말하세요 : ");
	scanf_s("%d", &num1);

	char Aalpha;
	int Acash;

	printf("알파벳을 입력하세요 : ");
	scanf_s("%c", &Aalpha);
	

	printf("돈을 입력하세요 : ");
	scanf_s("%d", &Acash);

	Bitcoin* coin = (Bitcoin*)malloc(sizeof(Bitcoin));
	coin->alpha = Aalpha;
	coin->cash = Acash;

	Bitcoin* tmp;
	if (num1 == 0) {
		coin->next = head;
		return coin;
	}
	for (tmp = head; tmp != NULL; tmp = tmp->next, x++) {
		if (x == num1 - 1) {

			coin->next = tmp->next;
			tmp->next = coin;
			break;

		}
	}

	return head;

}

int main() {
	int num = 0;
	Bitcoin* head = NULL;
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

