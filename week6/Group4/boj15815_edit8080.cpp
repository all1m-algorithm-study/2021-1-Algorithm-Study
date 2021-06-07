/*
* 1. 숫자는 스택에 push 한다.
* 2. 연산자를 만나면 스택의 가장 위에 있는 값 두 개를 pop하여 연산한다.
* 3. 연산 결과값을 스택에 다시 push 한다.
* 
* 시간복잡도 = O(n) (n : 수식의 길이)
*/

#include <iostream>
#include <stack>

using namespace std;

int postfix(string &equation) {
	stack<int> value;
	int x1, x2;

	for (int i = 0; i < equation.length(); i++) {
		switch (equation[i]) {
		case '+': 
			x1 = value.top(); value.pop();
			x2 = value.top(); value.pop();
			value.push(x2 + x1);
			break;
		case '-':
			x1 = value.top(); value.pop();
			x2 = value.top(); value.pop();
			value.push(x2 - x1);
			break;
		case '*':
			x1 = value.top(); value.pop();
			x2 = value.top(); value.pop();
			value.push(x2 * x1);
			break;
		case '/':
			x1 = value.top(); value.pop();
			x2 = value.top(); value.pop();
			value.push(x2 / x1);
			break;
		default:
			value.push(equation[i]-'0');
		}
	}
	return value.top();
}

int main(){
	string equation;
	cin >> equation;

	cout << postfix(equation);
}
