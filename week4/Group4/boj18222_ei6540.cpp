#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//pair의 첫째 값은 진짜 답, 둘째 값은 subset이 0으로 시작하는지 1으로 시작하는지 여부
long long devide_conquer(long long a) {
	if (a == 0) {
		return 0;
	}

	return !devide_conquer(a - (long long)pow(2, (long long)log2(a)));
}

void solve() {

	long long N;
	cin >> N;
	cout << devide_conquer(N-1)<<'\n';
	
	
}

int main() {
	init();
	solve();
}
