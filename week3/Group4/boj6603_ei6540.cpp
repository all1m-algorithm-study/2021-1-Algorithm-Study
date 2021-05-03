#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void run(int idx, vector<int> &v, int cnt, int ans[]) {
	//cnt번째 숫자 저장
	if (idx < N && cnt <= 5) {
		ans[cnt] = v[idx];
	}

	//전체-현재벡터인덱스(남은 쓸 수 있는 수)보다 ans에남은 자리가 많다.
	//if(N-idx < 6-cnt)
	if (N - idx < 6 - cnt) {
		return;
	}
	//이번이 마지막 숫자였으면 재귀 종료
	else if (cnt == 5) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	//다음 재귀 호출
	for (int i = 1; i <= N-5; i++) {
		run(idx+i, v, cnt + 1, ans);
	}
	
}

void solve() {
	
	while (1) {
		//S개수
		cin >> N;
		if (N == 0) break;

		//재료준비
		vector<int> v(N);
		int ans[6];
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		//6개 고르는 배열 돌리기!
		for (int i = 0; i <= N-6; i++) {
			run(i, v, 0, ans);
		}
		cout << '\n';

	}
}

int main() {
	init();
	solve();
}
