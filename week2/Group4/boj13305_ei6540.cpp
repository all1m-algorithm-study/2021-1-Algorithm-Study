#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;//가격 오름차순
}

void solve() {
	
	int n;
	cin >> n;
	//위치, 기름값
	vector<pair<int,int>> city(n);
	vector<int> road(n - 1);

	int end = n-1;
	
	for (int i = 0; i < n-1; i++) {
		cin >> road[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> city[i].second;
		city[i].first = i;
	}
	city[n - 1].second = 1000000001;
	sort(city.begin(), city.end(), compare);

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long tmpsum = 0;
		if (city[i].first < end) {
			for (int j = city[i].first; j < end; j++) {
				tmpsum += road[j];
			}
			sum += (long long)tmpsum * city[i].second;
			end = city[i].first;
		}
	}

	cout << sum;
}

int main() {
	init();
	solve();
}
