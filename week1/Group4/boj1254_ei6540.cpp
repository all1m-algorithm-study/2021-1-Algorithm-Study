#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>

char ch[1000];
int len = 0;
int num = 0;
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool isPalindrome() {

	for (int i = 0; i < num/2; i++) {
		if (ch[i] != ch[num - i - 1]) {
			return false;
		}
	}
	return true;
}

void solve() {
	string s;
	cin >> s;

	for(int i=0; i<s.length();i++){
		ch[i] = s[i];
	}

	len = s.length();
	num = len;

	if (isPalindrome()) {
		cout << num;
		return;
	}

	ch[num] = ch[0];
	num++;

	if (isPalindrome()) {
		cout << num;
		return;
	}

	for (int i = 1; i < len; i++) {
		memmove(ch + len + 1, ch + len, sizeof(char) * i);
		ch[len] = ch[i];
		num++;

		
		if (isPalindrome()) {
			cout << num<<'\n';
			return;
		}
	}
}

int main() {
	init();
	solve();
}
