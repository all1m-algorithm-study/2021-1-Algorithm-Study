#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int N;
char v[64][64];
queue<char> s;
int cnt;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void run(int cnt, int x, int y) {
	//cout << cnt << "일때 x, y는 " << x << y;
	//종료조건
	if (cnt == 1) {
		s.push(v[x][y]);
		return;
	}
	
	// 모두 같은지 확인
	bool flag = true;
	for (int i = x; i < x + cnt; i++) {
		for (int j = y; j < y + cnt; j++) {
			if (v[i][j] != v[x][y]) {
				flag = false;
				break;
			}
		}
		if (flag == false) {
			break;
		}
	}

	//같으면 stack에 쌓고 return
	if (flag == true) {
		//cout << ", ::: false\n";
		s.push(v[x][y]);
	}
	//다르면 재귀함수 호출;
	else {
		//cout << ", ::: true\n";
		s.push('(');
		run(cnt/2, x, y);
		run(cnt/2, x, y + cnt/2);
		run(cnt/2, x + cnt/2, y);
		run(cnt/2, x + cnt/2, y + cnt/2);
		s.push(')');
	}
	return;
}

void solve() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	run(N, 0, 0);

	while (!s.empty()) {
		cout << s.front();
		s.pop();
	}

}

int main() {
	init();
	solve();
}
