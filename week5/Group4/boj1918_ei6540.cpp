#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;


void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

//연산자 우선순위를 알려주는 함수
int precedence(char ch) {
	if (ch == '(') return 0;
	if (ch == '+' || ch == '-') return 1;
	else if (ch == '*' || ch == '/') return 2;
}

void solve() {
	
	string line;
	cin >> line;

	string answer;
	stack<char> s;

	// line을 한 문자씩 돌며 후위표현식으로 만들기 위해 검사한다.
	for (char ch : line) {
		// 영문자가 나오면 바로 저장해둔다.
		if ('A' <= ch && 'Z' >= ch) {
			answer = answer + ch;
		}
		// 괄호가 나오면 계산을 위해 스택에 문자를 저장해둔다.
		else if (ch == '(') {
			s.push(ch);
		}
		// 닫는 괄호가 나오면 제일 가까운 여는괄호를 찾는다.
		else if (ch == ')') {
			while (!s.empty()) {
				char op = s.top();
				s.pop();
				if (op == '(') break;
				answer = answer + op;
			}
		}
		// 다른 연산자가 나오면 스택에 있는 연산자와 우선순위를 비교해 answer에 붙인다.
		else {
			while (!s.empty() && (precedence(s.top()) >= precedence(ch))) {
				answer = answer + s.top();
				s.pop();
			}
			s.push(ch);
		}
		}
		// for문이 끝나고 남은 연산자를 스택 순서대로 출력한다.
		while (!s.empty()) {
			char op = s.top();
			s.pop();
			answer = answer + op;
		}
		cout << answer << '\n';

}

int main() {
	init();
	solve();
}

