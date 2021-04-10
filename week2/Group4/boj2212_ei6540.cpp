#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
// 0 1 2 3 4 5 6 7 8 9
// 0 1 0 1 0 0 2 1 0 1 
// 2+3
//집중국 시작부터 끝까지 1개 구간으로 받음
//차가 가장 큰 k-1개 구간을 자름
//8-3=5
//오름차순 정렬
// 1 3 6 6 7 9
//  2 3 0 1 2
// 제일 큰 것 빼기 제일 작은 것
//
bool desc(int a, int b) {
	return a > b;
}
void solve() {
	int N;
	cin >> N;
	int K;
	cin >> K;
	vector<int> v(N);

	//K가 N보다 클 때, 
	if (K >= N) {
		cout << 0;
		return;
	}

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int len = v[v.size() - 1] - v[0];

	vector<int> diff(N - 1);
	for (int i = 0; i < N - 1; i++) {
		diff[i] = v[i + 1] - v[i];
	}
	sort(diff.begin(), diff.end(), desc); 


	for (int i = 0; i < K-1; i++) {
		len -= diff[i];
	}
	cout << len;
}

int main() {
	init();
	solve();
}
