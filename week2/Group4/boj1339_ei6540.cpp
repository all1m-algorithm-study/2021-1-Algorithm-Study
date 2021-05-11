#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
bool desc(int a, int b) {
	return a > b;
}

void solve() {
	int N;
	cin >> N;
	vector<int> alph(26);
	vector<string> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < N; i++) {
		string s = v[i];
		int len = s.length();
		int tmd = 1;

		// 알파벳 위치에 따라 가중치 더해주기
		for (int j = len - 1; j > -1; j--) {
			alph[s[j] - 'A'] +=  tmd;
			tmd *= 10;
		}
	}
	// 가중치가 큰 알파벳이 먼저 오도록 정렬
	sort(alph.begin(), alph.end(), desc);

	int sum = 0;
	int num = 9;
	for (int i = 0; i < 26; i++) {
		//alph 빈도가 높은 것에 큰 num을 대입, 동시에 sum에 더해줌
		sum += alph[i] * num;
		num--;
	}
	cout << sum;
}

int main() {
	init();
	solve();
}
