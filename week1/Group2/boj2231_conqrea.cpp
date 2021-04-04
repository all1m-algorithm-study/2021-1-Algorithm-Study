#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n, a;
	string s;
	cin >> n;
	s = to_string(n);
	if (s.length() == 1) a = 1;
	else a = n - (9 * s.length() + 1);
	for (int i = a; i < n; i++) {
		int tmp = i, sum = i;
		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}