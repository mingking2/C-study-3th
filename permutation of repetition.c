// 적어도 한번은 중복된 수가 연속이 되도록

#include <stdio.h>

int swap(int a, int b, int arr[]) {
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
	return 0;

}

int cnt = 0;

int permutation(int arr[], int n, int m) {
	int ch = 0;
	if (n == 1) {
		
		for (int i = 0; i < m-1; i++) {
			if (arr[i] == arr[i + 1]) ch = -1;
		}

		if (ch == -1) {
			cnt++;
			for (int i = 0; i < m; i++) {
				printf("%d ", arr[i]);

			}
			printf("\n");
		}
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
			swap(i, n - 1, arr);
			permutation(arr, n - 1, m);
			swap(i, n - 1, arr);
	}

}


int main() {
	int arr[5] = { 1,4,3,2,3 };
	int n = sizeof(arr) / sizeof(int);
	int m = sizeof(arr) / sizeof(int);
	permutation(arr, n,m);

	printf("\n중복순열의 개수 : %d", cnt);
}
