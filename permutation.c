#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 순열

int swap(int a, int b, int arr[]) {
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	return 0;

}

int cnt = 0;

int permutation(int arr[], int n, int m) {
	if (n == 1) {
		cnt++;
		for (int i = 0; i < m;i++) {
			printf("%d ", arr[i]);
			
		}
		printf("\n");
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		swap(i, n - 1, arr);
		permutation(arr, n - 1,m);
		swap(i, n - 1, arr);
	}

}



int main() {
	srand(time(NULL));
	int num = 0;
	printf("배열의 크기를 입력하세요 : ");
	scanf_s("%d", &num);

	int* arr = (int*)malloc(sizeof(int)*num);
	int m = num;

	for (int i = 0; i < num; i++) {
		arr[i] = rand()%100;
		printf("%d ", arr[i]);
	}
	printf("\n===============================\n");

	/*combination(arr);*/

	

	printf("\n===============================\n");


	permutation(arr, num, m);

	printf("\n순열의 개수 : %d", cnt);


}
