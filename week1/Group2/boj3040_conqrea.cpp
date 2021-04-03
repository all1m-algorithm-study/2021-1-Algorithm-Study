#include <iostream>
using namespace std;

int main()
{
	int num[10], sum = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> num[i];
		sum += num[i];
	}

	for (int i = 1; i <= 8; i++) {
		for (int j = i + 1; j <= 9; j++) {
			if (sum - num[i] - num[j] == 100) {
				for (int k = 1; k <= 9; k++) {
					if (k == i || k == j)
						continue;
					cout << num[k] << endl;
				}
			}
		}
	}
}