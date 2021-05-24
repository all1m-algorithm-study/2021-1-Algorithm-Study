#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	stack<int> s;
	string a;
	int imsi1, imsi2;
	cin >> a;
	for (int i = 0; i < size(a); i++) {
		if (a[i] == '+') {
			imsi1 = s.top();
			s.pop();
			imsi2 = s.top();
			s.pop();
			s.push(imsi1 + imsi2);
		} else if (a[i] == '/') {
			imsi1 = s.top();
			s.pop();
			imsi2 = s.top();
			s.pop();
			s.push(imsi2/imsi1);
		} else if (a[i] == '*') {
			imsi1 = s.top();
			s.pop();
			imsi2 = s.top();
			s.pop();
			s.push(imsi1 * imsi2);
		} else if (a[i] == '-') {
			imsi1 = s.top();
			s.pop();
			imsi2 = s.top();
			s.pop();
			s.push( imsi2-imsi1);
		}
		else {
		s.push(a[i]-'0');
		}
	}
	cout << s.top();



}