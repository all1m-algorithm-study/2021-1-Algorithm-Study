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
	
	int N;
	cin >> N;
	int temp = 0;
	int tri[1000];

	//삼각수를 미리 계산해둡니다. --> O(n)
	for (int i = 0; i < 1000; i++) {
		tri[i] = (i * (i + 1)) / 2;
	}

	while (N--) {
		cin >> temp;
		bool result = false;

		for (int i = 1; i < 45; i++) {
			for (int j = 1; j < 45; j++) {
				for (int k = 1; k < 45; k++) {
					if (tri[i] + tri[j] + tri[k] == temp) {
						result = true;
						break;
					}
				}
				//if (result == true) break;
			}
			//if (result == true) break;
		}

		if (result == true) {
			cout << 1 << '\n';
		}
		else cout << 0 << '\n';

	}
}

int main() {
	init();
	solve();
}
