#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<long long int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
 
	for (int i = 0; i < m; i++) {
		vector<long long int>::iterator it = v.begin();

		sort(v.begin(), v.end());

		v[0] += v[1];
		v[1] = v[0];

		long long int tmp = v[1];

		v.erase(it, it + 2);	
		v.push_back(tmp);
		v.push_back(tmp);
			
		
	}

	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	cout << sum;
	
}

int main() {
	init();
	solve();
}
