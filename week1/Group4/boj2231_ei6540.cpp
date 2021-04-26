#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


void solve() {
	char num[6] = { 0, };
	int N;
	bool flag = false;
	cin >> N;
	//1,000,000
	//abc = 100a+10b+c + a+b+c(a, b, c는 0-9)
	//abcd = 1000a+100b+10c+d  +  a+b+c
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					for (int m = 0; m < 10; m++) {
						for (int n = 0; n < 10; n++) {
							
							if (100001 * i + 10001 * j + 1001 * k + 101 * l + 11 * m + 2 * n==N) {
								cout << 100000 * i + 10000 * j + 1000 * k + 100 * l + 10 * m + n;
								flag = true;
								return;
							}
						}
					}
				}
			}
		}
	}
	if (flag == false) cout << 0;
}

int main() {
	init();
	solve();
}

