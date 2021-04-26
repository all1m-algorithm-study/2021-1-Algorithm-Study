#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool comp(const pair<int,int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

void solve() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		vector<pair<int,int>> v(N);

		for (int i = 0; i < N; i++) {
			cin >> v[i].first >> v[i].second;
		}

		sort(v.begin(), v.end(), comp);

		int tmp = v[0].second;
		int num = 1;
		for (int i = 1; i < N; i++) {
			if (tmp > v[i].second) {
				num++;
				tmp = v[i].second;
			}
		}
		cout << num<<'\n';
	}
	
}

int main() {
	init();
	solve();
}
