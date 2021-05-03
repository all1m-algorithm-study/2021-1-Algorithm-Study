#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

// 만들지 못하는 가장 작은 무게
// 추 오름차순 정렬

void solve() {
	int N;
	cin >> N;
	vector<int> v(N);
	
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	
	//1이 존재하지 않음
	if (v[0] != 1) {
		cout << 1;
		return;
	}
	//1이 존재함
	else {
		int sum = 1;
		for (int i = 1; i < N; i++) {
			//합+1 보다 큰 수가 v[i]에 있다면 만드는게 불가능
			if (v[i] > sum + 1) {
				
				break;
			}
			sum += v[i];
		}
		cout << sum + 1;
	}
}

int main() {
	init();
	solve();
}
