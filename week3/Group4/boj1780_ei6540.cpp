#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N;
int numofz = 0;
int numofo = 0;
int numoft = 0;
int paper[2187][2187] = { 0, };

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void run(int a, int b, int c, int d) {

	int sum = 0;
	for (int i = a; i < b; i++) {
		for (int j = c; j < d; j++) {
			sum += paper[i][j];
		}
	}

	//조건에 맞으면 종이 개수 ++
	if (sum == -2187 * (b - a) * (b - a)) {
		//cout << b - a << "일 때 -1 종이개수 ++\n";
		//cout << "이때 a는 " << a << ", c는 " << c << '\n';
		numoft++;
		if (b - a == 1) {
			return;
		}
	}
	else if (sum == (b - a) * (b - a)) {
		//cout << b - a << "일 때 1 종이개수 ++\n";
		//cout << "이때 a는 " << a << ", c는 " << c << '\n';
		numofo++;
		if (b - a == 1) {
			return;
		}
	}
	else if (sum == 0) {
		//cout << b - a << "일 때 0 종이개수 ++\n";
		//cout << "이때 a는 " << a << ", c는 " << c << '\n';
		numofz++;
		if (b - a == 1) {
			return;
		}
	}
	//조건에 맞지 않으면 종이를 자름
	else {
		int horizon[4] = { a,  a + (b - a) / 3, a + 2 * (b - a) / 3, b };
		int vertical[4] = { c, c + (d - c) / 3, c + 2 * (d - c) / 3, d };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				run(horizon[i], horizon[i + 1], vertical[j], vertical[j + 1]);
			}
		}
	}


	
}

void solve() {
	//재료준비
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
			if (paper[i][j] == -1) {
				paper[i][j] = -2187;
			}
		}
	}
	run(0, N, 0, N);

	cout << numoft << '\n' << numofz << '\n' << numofo;
	
}

int main() {
	init();
	solve();
}
