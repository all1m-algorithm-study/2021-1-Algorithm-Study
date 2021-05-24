#include<stdio.h>
#pragma warning(disable:4996)
#define ARRSIZE 1000000
void mergeArr(int* a, int n, int* b, int m);

int main(void) {
	int n, m;
	int aArr[ARRSIZE];
	int bArr[ARRSIZE];
	int* mArr;
	//printf("왜안돼...");

	//배열 A의 크기 N, 배열 B의 크기 M
	scanf("%d %d", &n, &m);

	//배열 A의 내용, 배열 B의 내용
	for (int i = 0; i < n; i++)
		scanf("%d", &aArr[i]);

	for (int i = 0; i < m; i++)
		scanf("%d", &bArr[i]);

	
	mergeArr(aArr, n, bArr, m);

	return 0;
}
void mergeArr(int* a, int n, int* b, int m) {
	int result[2*ARRSIZE];
	int i = 0, j = 0, k = 0;

	while (i < n && j < m) {
		//a배열값과 b 배열값을 0번 요소부터 비교해서 result 배열에 넣음
		if (a[i] < b[j]) result[k++] = a[i++];
		else result[k++] = b[j++];
	}

	//a 배열 길이와 b 배열 길이가 다를 경우 남은 요소를 배열에 넣음
	while (i < n) result[k++] = a[i++];
	while (j < m) result[k++] = b[j++];


	//결과 배열 출력
	for (int i = 0; i < (n + m); i++) {
		printf("%d ", result[i]);
	}

	return;
}