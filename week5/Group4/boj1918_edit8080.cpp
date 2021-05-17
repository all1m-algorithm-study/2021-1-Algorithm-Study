// 1. 연산자 우선순위를 설정한다. ( (, ) : 1순위 *, / : 2순위, +, - : 3순위)
// 2. 알파벳은 결과에 계속 더해간다.  
// 3. 연산자를 판별한다. 동일한 순위는 앞에 있을수록 우선순위가 높다.
// 3-1. ')'를 만나면 '('를 만날때까지 저장된 연산자를 결과에 더함 (가장 높은 우선순위)
// 3-2. '*', '/'를 만나면 우선순위가 높은 '(' 와 우선순위가 낮은 '+', '-' 가 아니면 앞에 있는 연산자를 결과에 더함
// 3-3. '+', '-'를 만나면 우선순위가 높은 '(' 를 만날때까지 연산자를 결과에 더함
// 
// 시간복잡도 = O(n)

#include <iostream>
#include <stack>

using namespace std;

string postfix(string &infix) {
	stack<char> s;
	string result = "";

	for (int i = 0; i < infix.length(); i++) {
		if (infix[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				result += s.top(); s.pop();
			}
			s.pop();
		}
		else if (infix[i] == '*' || infix[i] == '/') {
			// *, / 우선순위
			while (!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-') {
				result += s.top(); s.pop();
			}
			s.push(infix[i]);
		}
		else if (infix[i] == '+' || infix[i] == '-') {
			while (!s.empty() && s.top() != '(') {
				result += s.top(); s.pop();
			}
			s.push(infix[i]);
		}
		else if (infix[i] == '(')
			s.push(infix[i]);
		else
			result += infix[i];	
	}
	while (!s.empty()) {
		result += s.top(); s.pop();
	}
	return result;
}

int main(){
	string infix;

	cin >> infix;

	cout << postfix(infix);
}
