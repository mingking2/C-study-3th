#include <stdio.h>

int sum(int n) {
	if (n < 1) return 0;
	return n + sum(n - 1);
}

int factorial(int n) {
	if (n <= 1) return 1;
	return n * factorial(n-1);
}

int fibo(int n) {
	if (n <= 1) return n;
	return fibo(n - 1) + fibo(n - 2);
}


int main() {
	
	while (1) {
		int n, c = 0;
		printf("\n재귀함수를 이용한 계산기 (종료 : -1)\n");
		printf("----------------------------------\n");
		printf("1. 합\n");
		printf("2. 곱\n");
		printf("3. 피보나치수열\n");
		printf("----------------------------------\n");
		scanf_s("%d", &c);
		getchar();

		if (c == -1) break;

		switch (c) {
		case 1:
			printf("1 ~ n 까지의 합 (n을 입력) : ");
			scanf_s("%d", &n);

			printf("----------------------------------\n");
			printf("결과 : %d\n", sum(n));
			break;
		case 2:
			printf("n! (n을 입력) : ");
			scanf_s("%d", &n);

			printf("----------------------------------\n");
			printf("결과 : %d\n", factorial(n));

			break;
		case 3:
			printf("n+1번째 피보나치수열의 수 (n을 입력) : ");
			scanf_s("%d", &n);

			printf("----------------------------------\n");
			printf("%d번째 피보나치수열의 수 : %d\n",n+1,fibo(n));

			break;
		default:
			break;
		}
	}
}
