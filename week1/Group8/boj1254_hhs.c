#include <stdio.h>
#include <string.h>//스트링 관련 함수 쓰기 위한 헤더
#pragma warning(disable:4996)
int isPal(char* str, int len);

int main(void) {
	char str[1000];
	char pal[1000];

	int strNum = 0;
	int minNum = 0;
	int idx = 0;

	scanf("%s", str);
	
	//스트링의 길이를 strNum, minNum에 저장
	strNum = strlen(str);
	minNum = strNum;

	//pal에 str(input) 문자열을 복사
	strcpy(pal, str);

	int tof = 1;//true or false
	tof = isPal(str, strNum);

	//첫번째 isPal의 결과가 참이면 str 자체가 팰린드롬
	if (tof) {
		printf("%d", strNum);
		return 0;
	}

	/*
	str 자체가 팰린드롬이 아니라면 길이를 1 증가,
	pal에 문자열을 덧붙여가며 팰린드롬 여부 확인, 팰린드롬이면 1출력
	*/
	else {
		while (1) {
			strcpy(pal, str);
			tof = 1;
			idx++;
			for (int i = idx - 1; i >= 0; i--) {
				pal[strNum - 1 + idx-i] = str[i];
			}
			
			tof = isPal(pal, minNum + idx);

			if (tof) {
				printf("%d", minNum+idx);
				return 0;
			}
		}
	}



	return 0;
}

/*
문자열의 중간을 기준으로 앞뒤가 같으면 1, 다르면 0 리턴
(팰린드롬 여부 확인)
* /
int isPal(char* str, int len) {
	int tof = 1;
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]){
			tof = 0;
			break;
		}
	}

	return tof;
}