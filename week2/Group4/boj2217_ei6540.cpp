#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool desc(int a, int b) {
	return a > b;
}

//많이 들 수 있는게 좋은 밧줄
void solve() {
	int N;
	cin >> N;

	vector<int> rope(N);
	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}
	//내림차순 정렬
	sort(rope.begin(), rope.end(), desc);

	for (int i = 0; i < N; i++) {
		rope[i] = rope[i] * (i + 1);
	}
	sort(rope.begin(), rope.end(), desc);

	cout << rope[0];
	
}

int main() {
	init();
	solve();
}
