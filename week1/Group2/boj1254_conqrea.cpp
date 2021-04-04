#include <iostream>
#include <string>
using namespace std;

string s;

bool isPalindrome(int a, int b) {
	bool isThat = true;
	for (int i = a, j = b; i <= (a + b) / 2; i++, j--) {
		if (s[i] != s[j]) {
			isThat = false;
			break;
		}
	}
	return isThat;
}

int main()
{
	int minLen = 1001;
	cin >> s;
	
	for (int i = s.length()-1; i >= 0; i--) {
			if (isPalindrome(i, s.length() - 1)) {
				if (s.length() + i < minLen)
					minLen = s.length() + i;
			}
	}

	if (minLen == 1001)
		cout << s.length() * 2 - 1;
	else
		cout << minLen;
}