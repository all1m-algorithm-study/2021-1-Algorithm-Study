#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h>
#include <string.h>
#include<stack>
using namespace std;

int main(void) {
	int ops;
	char operation[101];//연산식
	double numOP[27];

	char changeOP = 'A';
	double tmpA, tmpB;//stack에서 pop하는 임시 피연산자
	double result;

	stack<double> operand;//피연산자

	scanf("%d", &ops);//피연산자 개수
	scanf("%s", operation);
	for (int i = 0; i < ops; i++) {
		scanf("%lf", &numOP[i]);
	}
	//printf("before: %s\n", operation);


	/*알파벳으로 된 피연산자를 각 피연산자에 대응되는 값으로 치환->여기서 에러난듯?*/
	/*
	for (int i = 0; i < ops; i++) {
		//printf("changeOP: %c\n", changeOP);
		char* ptr = strchr(operation, changeOP);

		while (ptr != NULL) {// 검색된 문자가 없을 때까지 반복
			ptr = strchr(operation, changeOP);
			if (ptr) {
				*ptr = (char)(numOP[i]+48);  // 숫자로 변경
			}
		}

		changeOP++;//다음 알파벳으로!
	}
	//printf("after: %s\n", operation);
	*/

	/*후위 연산식 풀기*/
	for (int i = 0; i < strlen(operation); i++) {
		if (operation[i] >= 65 && operation[i] <= 90) {//숫자이면 스택에 쌓기
			operand.push(numOP[operation[i]-'A']);
			//printf("push : %.2lf\n", (double)((int)operation[i] - 48));
		}
		else {//연산자이면
			tmpB = operand.top();
			//printf("pop : %.2lf\n", operand.top());
			operand.pop();
			tmpA = operand.top();
			//printf("pop : %.2lf\n", tmpA);
			operand.pop();

			if (operation[i] == '+') {
				//printf("operator : +\n");
				result = tmpA + tmpB;
			}
			else if (operation[i] == '-') {
				//printf("operator : -\n");
				result = (double)tmpA - (double)tmpB;
				
			}
			else if (operation[i] == '*') {
				//printf("operator : *\n");
				result = tmpA * tmpB;
			}
			else {
				//printf("operator : /\n");
				result = (double)tmpA / (double)tmpB;
			}
			//printf("result push : %.2lf\n", result);
			operand.push(result);
		}
	}

	printf("%.2lf", operand.top());
	operand.pop();

	return 0;
}