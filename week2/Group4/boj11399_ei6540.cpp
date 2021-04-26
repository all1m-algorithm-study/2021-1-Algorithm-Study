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
	
	int n;
	cin >> n;
	vector<int> people(n);
	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}

	//오름차순
	sort(people.begin(), people.end());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += people[i] * (n - i);
	}
	cout << sum;
}

int main() {
	init();
	solve();
}
