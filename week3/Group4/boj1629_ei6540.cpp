#include <iostream>
using namespace std;

int A, B, C;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

// 시간초과가 난다면 분할정복을 해보자!
// 재귀함수에서 짝수가 들어오면 반*반
// 재귀함수에서 홀수가 들어오면 반*반*A

long long run(int iter) {
	//base case
	if (iter == 1) return A % C;
	long long tmp_ans;
	long long devide;

	devide = run(iter / 2)%C;
	tmp_ans = devide * devide;
	//남은횟수 n이 홀수인 경우
	if (iter % 2 == 1) {
		tmp_ans = (tmp_ans % C * A % C) % C;
	}
	//남은횟수 n이 짝수인 경우
	else if (iter % 2 == 0) {
		tmp_ans = tmp_ans%C;
	}
	return tmp_ans;
}

void solve() {
	cin >> A >> B >> C;
	long long answer = run(B);
	cout << answer;
}

int main() {
	init();
	solve();
}
