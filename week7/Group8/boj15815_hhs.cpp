#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h>
#include <string.h>
#include<stack>
using namespace std;

int main(void) {
	char operation[101];//연산식

	char changeOP = 'A';
	int tmpA, tmpB;//stack에서 pop하는 임시 피연산자
	int result;

	stack<int> operand;//피연산자

	scanf("%s", operation);


	/*후위 연산식 풀기*/
	for (int i = 0; i < strlen(operation); i++) {
		if (operation[i] >= 48 && operation[i] <= 57) {//숫자이면 스택에 쌓기
			operand.push(operation[i] - 48);
			//printf("push : %d\n", operation[i]-48);
		}
		else {//연산자이면
			tmpB = operand.top();
			//printf("pop : %d\n", operand.top());
			operand.pop();
			tmpA = operand.top();
			//printf("pop : %d\n", tmpA);
			operand.pop();

			if (operation[i] == '+') {
				//printf("operator : +\n");
				result = tmpA + tmpB;
			}
			else if (operation[i] == '-') {
				//printf("operator : -\n");
				result = tmpA - tmpB;
			}
			else if (operation[i] == '*') {
				//printf("operator : *\n");
				result = tmpA * tmpB;
			}
			else {
				//printf("operator : /\n");
				result = tmpA / tmpB;
			}
			//printf("result push : %d\n", result);
			operand.push(result);
		}
	}

	printf("%d", operand.top());
	operand.pop();

	return 0;
}