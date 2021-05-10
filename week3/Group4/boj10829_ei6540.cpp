#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void run(long long n) {
	//만약 들어온 수가 1이 아니라면, 
	if (n != 1) {
		//뒷 숫자를 찾기위한 재귀함수를 돌린다.
		run(n / 2);
	}
	//출력문을 함수호출 밑에 두면 자동으로 반대로 출력된다.
	cout << n % 2;
}

void solve() {
	long long N;
	cin >> N;
	run(N);
}

int main() {
	init();
	solve();
}
