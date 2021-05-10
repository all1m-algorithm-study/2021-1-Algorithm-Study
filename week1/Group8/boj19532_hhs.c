#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int a, b, c, d, e, f;
	int x = 0, y = 0;

	//변수에 입력받음
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);


	//연립방정식을 만족하는 i, j가 있으면 해 변수에 저장 후 반복문 탈출
	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if ((a * i + b * j == c) && (d * i + e * j == f)) {
				x = i;
				y = j;
				break;
			}
		}
		if (x)
			break;
	}

	//결과 출력
	printf("%d %d", x, y);

	return 0;
}