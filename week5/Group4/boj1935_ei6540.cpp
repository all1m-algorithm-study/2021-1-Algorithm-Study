#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;


void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	// 변수 개수를 먼저 선언한 후 밑 for문에서 받는다.
	int operand[26];
	int n;
	cin >> n;
	string postfix;
	cin >> postfix;
	for (int i = 0; i < n; i++) {
		cin >> operand[i];
	}
	// 후위표기식은 스택을 주로 사용한다.
	stack<double> s;
	for (char ch : postfix) {

		// ch가 문자인 경우, 숫자를 계산해야함에 주의
		// 답이 소수점 둘째자리까지 나올 수 있음
		if (ch >= 'A' && ch <= 'Z') {
			s.push((double)operand[ch - 'A']);
		}
		// ch가 연산자인 경우, 스택 규칙에 따라 op2가 먼저 pop됨
		else {
			double op2 = s.top(); s.pop();
			double op1 = s.top(); s.pop();

			if (ch == '+') {
				s.push(op1 + op2);
			}
			else if (ch == '-') {
				s.push(op1 - op2);
			}
			else if (ch == '*') {
				s.push(op1 * op2);
			}
			else if (ch == '/') {
				s.push(op1 / op2);
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top();

}

int main() {
	init();
	solve();
}

