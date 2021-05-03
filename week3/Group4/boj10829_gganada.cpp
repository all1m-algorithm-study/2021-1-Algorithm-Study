#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <string.h>
#include <math.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	bool Tnum[1000] = { 0};
	string n;
	int ni[15] = { 0 };
	int carry =0;
	int gap;
	int num = 0;
	int sum;

	cin >> n;

	for (int i = 0; i < size(n); i++) {
		ni[i]= n[i]-'0';
	}

	while (1) {
		sum = 0;
		carry = 0;
		for (int i = 0; i < size(n); i++) {
			gap = ni[i];
			ni[i] = (10 * carry + ni[i]) / 2;
			carry = gap % 2;
			sum += ni[i];
		}
		Tnum[num] = carry;
		num++;

		if (!sum) break;
	}

	for (int i = 0; i < num ; i++) {
		cout << Tnum[num  - 1-i];
	}

}