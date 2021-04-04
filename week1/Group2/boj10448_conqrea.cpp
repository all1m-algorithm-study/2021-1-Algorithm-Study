#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++) {
		int T;
		bool isTriAble = false;
		cin >> T;
		for (int i = 1, a = 1; a <= 1000; i++, a+=i) {
			for (int j = i, b = a; b <= 1000; j++, b += j) {
				for (int l = j, c = b; c <= 1000; l++, c += l) {
					if (T == a + b + c) {
						isTriAble = true;
						break;
					}
				}
				if (isTriAble)
					break;
			}
			if (isTriAble)
				break;
		}
		if (isTriAble)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}