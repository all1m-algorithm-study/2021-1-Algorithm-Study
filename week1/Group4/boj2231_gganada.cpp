#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	cin >> a;
	int c;
	int sang = 0;
	int sum;
	for (int i = 1; i <= a; i++) {
		c = i;
		sum = 0;
		sum += c;
		for (int m = 0; m < 8; m++) {
			sum += c % 10;
			c /= 10;
	
		}
		if (sum == a) {
			sang = i;
			break;
		}
	}
	cout << sang;

	
}