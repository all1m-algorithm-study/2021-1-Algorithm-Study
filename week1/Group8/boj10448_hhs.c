#include <stdio.h>
#pragma warning(disable:4996)
int Tn(int x);

int main(void) {
	int num;
	int n = 0;
	int testcase;
	int tof = 0;//true or false

	scanf("%d", &testcase);

	for(int a = 0; a < testcase; a++){
		tof = 0;
		scanf("%d", &num);

		/*
		num(input)이 몇 번째 삼각수까지로 표현될 수 있는지
		num보다 작은 최대의 삼각수까지로 표현
		*/
		while (num >= Tn(n)) {
			n++;
		}

		//3가지 1~n번째 삼각수까지
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				for (int k = 1; k < n; k++) {
					//num이 3개의 삼각수로 표현될 수 있다면 1 출력후 반복문 탈출
					if (num - (Tn(i) + Tn(j) + Tn(k)) == 0) {
						printf("1\n");
						tof = 1;
						break;
					}
				}
				if (tof)
					break;
			}
			if (tof)
				break;
		}
		
		//tof == 0이면 0출력
		if(!tof)
			printf("0\n");
	}

	return 0;
}

//삼각수 Tn 공식을 함수로
int Tn(int x) {
	return (x * (x + 1)) / 2;
}