#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int num;
	int numcopy;
	int tmpresult;
	int decom = 0;
	//decom 변수가 최종 결과

	scanf("%d", &num);

	for (int i = 1; i < num; i++) {
		/*
		num(input)에 i를 생성자라고 가정하고 뺌
		이제 tmpresult에  i의 각 자리수의 값을 빼기 위해 numcopy에 i를 넣음
		*/
		tmpresult = num - i;
		numcopy = i;

		//numcopy의 각 자리수 추출해서 뺌
		while (numcopy != 0) {
			tmpresult -= (numcopy % 10);
			numcopy /= 10;
		}
		
		//num(input)-i-i의 각 자리수 = 0이면 i는 생성자, 반복문 탈출
		if (tmpresult == 0){
			decom = i;
			break;
		}
	}

	printf("%d", decom);

	return 0;
}