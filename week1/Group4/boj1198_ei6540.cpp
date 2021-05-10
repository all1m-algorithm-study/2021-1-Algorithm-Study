#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void solve() {
	
	int N;
	cin >> N;
	vector<pair<double, double>> v(N);
	double max = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++){
				double s = 0.5 * abs((((v[i].second-v[j].second) * (v[k].first-v[j].first)) - ((v[i].first-v[j].first) * (v[k].second-v[j].second))));
				if (max < s) {
					max = s;
				}
			}
		}
	}
	printf("%.9f", max);
}

int main() {
	init();
	solve();
}
