#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	int n;
	double arr[26];
	stack<double> numbers;
	string s;
	
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			double a, b, c;
			b = numbers.top(); numbers.pop();
			a = numbers.top(); numbers.pop();
			switch (s[i]) {
			case '+':
				c = a + b;
				break;
			case '-':
				c = a - b;
				break;
			case '*':
				c = a * b;
				break;
			case '/':
				c = a / b;
				break;
			}
			numbers.push(c);
		}
		else {
			numbers.push(arr[(int)(s[i] - 'A')]);
		}
	}
	printf("%.2lf", numbers.top());
}