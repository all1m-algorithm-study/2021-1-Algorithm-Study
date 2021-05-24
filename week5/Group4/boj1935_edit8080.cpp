// 1. 스택을 통한 후위표기식 구현
// 2. 값을  스택에 삽입한 후 연산자를 만나면 두 개를 뽑아 계산 → 이후 스택에 결과값 삽입
//
// 시간복잡도 = O(n)

#include <iostream>
#include <stack>

#define SIZE 26

using namespace std;

double postfix(double *value, string input) {
	stack<double> s;
	double n1, n2;

	for (int i = 0; i < (int)input.length(); i++) {
		switch (input[i]) {
		case '+':
			n1 = s.top(); s.pop();
			n2 = s.top(); s.pop();
			s.push(n2 + n1);
			break;
		case '-':
			n1 = s.top(); s.pop();
			n2 = s.top(); s.pop();
			s.push(n2 - n1);
			break;
		case '*':
			n1 = s.top(); s.pop();
			n2 = s.top(); s.pop();
			s.push(n2 * n1);
			break;
		case '/':
			n1 = s.top(); s.pop();
			n2 = s.top(); s.pop();
			s.push(n2 / n1);
			break;
		default:
			s.push(value[input[i] - 'A']);
			break;
		}
	}
	return s.top();
}

int main(){
	cout.setf(ios:: fixed);
	cout.precision(2);

	int n;
	string input;
	double value[SIZE];

	cin >> n >> input;
	
	for (int i = 0; i < n; i++) 
		cin >> value[i];

	cout << postfix(value, input);

	return 0;
}
