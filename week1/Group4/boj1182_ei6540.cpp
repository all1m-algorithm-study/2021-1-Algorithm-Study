#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int cnt = 0;
int v[21];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void findcnt(int i, int sum) {

	//i번째 수를 담는다
	sum += v[i];
	if (N <= i) {
		return;
	}
	else if (S == sum) {
		cnt++;
	}
	//i 담은거 유지
	findcnt(i + 1, sum);
	//i 담은거 취소
	findcnt(i + 1, sum - v[i]);

}

void solve() {
	
	cin >> N >> S;
	
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	findcnt(0, 0);
	cout << cnt;
}

int main() {
	init();
	solve();
}
