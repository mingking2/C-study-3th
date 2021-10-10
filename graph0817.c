
// 그래프 예) 지하철역 : NO부모노드 ㅇㅋ?, 평등한 노드(누구든지 연결) 
// ->> 노드 대신 vertex라고 부름
// ->> vertex를 잇는 선을 edge라고 부름
// 그래프 종류 : 무방향 그래프(=양방향 연결리스트), 방향 그래프(=단방향 연결리스트)
// 그래프 용어 : 인접 정점(하나의 정점에서 간선에 의해 직접연결), 차수(하나의 정점에 연결된 간선의 수)
//				 경로(간선을 따라갈 수 있는 길), 사이클(시작 정점과	종료 정점이 동일한 경로)

#include <stdio.h>
#define _CRT_SECURE_NO_WARNNINGS

//int arr1[4] = { 0,0,0,0 };
void dfs(int next, int end, int cnt, int arr[4][4]) {
	if (next == end) {
		printf("갈수있다\n");
		return;
	}
	else if(cnt>5){
		printf("갈수없다\n");
		return;
	}
	else {
		//arr1[next] = 1;
		int temp = next;
		for (int i = 0; i < 4; i++) {
			if (arr[next][i] == 1 /*&& arr1[i] != 1*/) {
				dfs(i,end,cnt+1,arr);
			}
		}
	}
}


int main() {
	int arr[4][4] = {
		{0,1,1,0},
		{1,0,0,0},
		{1,0,0,0},
		{0,0,0,0}
	};
	int start = 0;
	int end = 0;
	int cnt = 0;

	scanf_s("%d %d", &start, &end);
	dfs(start, end, cnt, arr);

	
}
