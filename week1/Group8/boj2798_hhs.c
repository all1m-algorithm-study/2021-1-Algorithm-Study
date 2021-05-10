#include <stdio.h>
#include <stdlib.h>//malloc 쓰기 위한 헤더
#pragma warning(disable:4996)

int main(void) {
	int N, M;
	int* card;
	int result = 0;
	int max = 0;

	scanf("%d %d", &N, &M);
	
	//카드의 개수만큼 배열 생성
	card = (int*)malloc(sizeof(int) * N);

	//각 카드의 값 입력
	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);

	/*
	i가 0~N, j가 i+1~N, k가 j+1~N인 동안 반복하면서
	i, j, k번째, 세 카드의 합을 result에 저장
	result가 M보다 작으면서 result가 max 변수의 값보다 크다면
	max에 result 값을 저장
	*/
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				result = card[i] + card[j] + card[k];
				if (M-result >= 0) {
					if (result > max)
						max = result;
				}
			}
		}
	}

	printf("%d", max);

	free(card);//card 배열 해제
	return 0;
}