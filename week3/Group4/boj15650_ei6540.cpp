#include <iostream>
using namespace std;
int N, M;
int ans[8];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void run(int node, int cnt) {
	//답 설정해주기
	ans[cnt] = node;

	//재귀 종료조건
	if (cnt == M - 1) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}

	//마지막 숫자가 너무 일찍 선택되면 그 함수는 끝
	else if (node == N) return;

	//다음줄 호출
	for (int i = node + 1; i < N + 1; i++) {
		run(i, cnt + 1);
	}
}

void solve() {
	
	cin >> N >> M;

	for (int j = 1; j <= N; j++) {
		run(j, 0);
	}
}

int main() {
	init();
	solve();
}
