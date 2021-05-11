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
	int N, L;
	cin >> N >> L;

	vector<int> broken(N);
	for (int i = 0; i < N; i++) {
		cin >> broken[i];
	}
	sort(broken.begin(), broken.end());

	int idx = 0;
	int tape = 0;
	int i = 0;
	while (i<=1000 && idx<N) {
		if (broken[idx] == i) {
			tape++;
			i += L;
			while (broken[idx] < i && (idx + 1) < N) {
				idx++;
			}
		}
		else i++;
	}
	cout << tape;
	
}

int main() {
	init();
	solve();
}
