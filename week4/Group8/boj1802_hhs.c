#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int DFold(char* str, int strLen);

int main(void) {
	int tCase;
	char paperFold[3000];
	int pFoldLen;
	int result;

	scanf("%d", &tCase);

	for (int i = 0; i < tCase; i++) {
		scanf("%s", paperFold);

		pFoldLen = strlen(paperFold);

		//동호의 방법대로 접으면 항상 접힌 횟수는 홀수가 됨,
		//따라서 짝수의 경우 고려할 필요 없음
		if (pFoldLen % 2 == 0)
			printf("NO\n");
		else if (pFoldLen == 1)
			printf("YES\n");
		else {
			result = DFold(paperFold, pFoldLen);
			if (result == 1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}
int DFold(char* str, int strLen) {
	int mid = strLen / 2;
	int i = 0;
	int j = strLen - 1;
	int strBool = 1;

	//printf("%d\n", mid);

	/*
		동호의 방법대로라면, mid(중간 지점)을 기준으로
		각 대칭되는 지점이 반대의 값을 가져야 함,
		한쪽이 in이면 대칭되는 한 쪽은 out이어야 함
	*/
	while (1) {
		//printf("%c %d\n", str[i], i);
		//printf("%c %d\n", str[j], j);

		if (str[i++] == str[j--]) {
			strBool = 0;
		}

		if (i == mid)
			break;
	}


	/*
		만약 false(0)이면 바로 값 리턴
		true(1)이면 mid 기준으로 앞쪽만 재귀로 다시 비교(뒷쪽은 앞쪽의 반전이므로 다시 비교할 필요 없음)
	*/
	if (strBool == 1 && mid > 2)
		return DFold(str, mid);
	else return strBool;
}