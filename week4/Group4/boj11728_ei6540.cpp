#include <iostream>
#include <vector>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void solve() {
	int N, M;
	cin >> N >> M;

	vector<int> arr_n(N);
	for (int i = 0; i < N; i++) {
		cin >> arr_n[i];
	}
	vector<int> arr_m(M);
	for (int i = 0; i < M; i++) {
		cin >> arr_m[i];
	}
	int i = 0;
	int j = 0;
	while (i < N && j < M) {
		// m이 더 크면 더 작은 n을 cout
		if (arr_n[i] < arr_m[j]) {
			cout << arr_n[i]<< " ";
			i++;
		}
		// n이 더 크면 더 작은 m을 cout
		else {
			cout << arr_m[j]<< " ";
			j++;
		}
	}

	while (i < N) {
		cout << arr_n[i] << " ";
		i++;
	}
	while (j < M) {
		cout << arr_m[j] << " ";
		j++;
	}
}

int main() {
	init();
	solve();
}
