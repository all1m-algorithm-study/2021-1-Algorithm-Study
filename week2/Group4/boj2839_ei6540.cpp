#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

//3과 5를 사용해 N만들기, 불가능하면 -1출력
void solve() {

	int n;
	cin >> n;

	//5의 배수면 몫 출력
	if (n % 5 == 0) {
		cout << n / 5 << '\n';
		return;
	}
	else {
		for (int i = n / 5 ; i >= 0; i--) {
			if ((n - 5 * i) % 3 == 0) {
				cout << ((n - 5 * i) / 3) + i << '\n';
				return;
			}
		}
		cout << -1 << '\n';
		return;
	}
	
}

int main() {
	init();
	solve();
}
