// 1. 스택을 통해 정상적인 괄호 문자열인지 확인
// 2. 괄호 문자열이라면 괄호 값 계산
//		괄호 시작 시 mul * 2 || 3 . 괄호 종료 후 mul / 2 || 3
// 3. (), [] 형태일 때만 sum에 더해줌
// 
// 시간복잡도 = O(n)

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 2. 괄호 값 계산
int bracket_value(string input) {
	int sum = 0;
	int mul = 1;
	stack<char> s;

	for (int i = 0; i < (int)input.length(); i++) {
		if (input[i] == '(') {
			s.push('(');
			mul *= 2;
		}
		else if (input[i] == '[') {
			s.push('[');
			mul *= 3;
		}
		else if (input[i] == ')') {
			if (input[i - 1] == '(')
				sum += mul;
			s.pop();
			mul /= 2;
		}
		else if (input[i] == ']') {
			if (input[i - 1] == '[')
				sum += mul;
			s.pop();
			mul /= 3;
		}
	}
	return sum;
}
// 1. 정상적인 괄호인지 체크
bool check_bracket(string input) {
	stack<char> s;

	for (int i = 0; i < (int)input.length(); i++) {
		if (input[i] == '(' || input[i] == '[')
			s.push(input[i]);
		else if (input[i] == ')') {
			if (!s.empty() && s.top() == '(')
				s.pop();
			else
				return false;
		}
		else if (input[i] == ']') {
			if (!s.empty() && s.top() == '[')
				s.pop();
			else
				return false;
		}
	}
	if (!s.empty())
		return false;
	return true;
}
int main(){
	string input;	

	cin >> input;

	if (check_bracket(input)) 
		cout << bracket_value(input);
	else
		cout << 0;

	return 0;
}
