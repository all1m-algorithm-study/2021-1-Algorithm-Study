#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N;
int sum;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void run(int line, int r, int c) {
	// 사분면 중 하나를 고른다.
	// 숫자를 쌓는다.
	int hfline = line / 2;
	int qtr = hfline * hfline;
	if (qtr == 0) {
		return;
	}

	if (line / 2 > r) {
		//1사분면
		if (line / 2 > c) {
			//cout << "1사분면 방문\n";
			sum += 0;
			run(hfline, r, c);
		}//2사분면
		else {
			//cout << "2사분면 방문\n";
			sum += qtr;
			run(hfline, r, c - hfline);
		}
	}
	else {
		//3사분면
		if (line / 2 > c) {
			//cout << "3사분면 방문\n";
			sum += 2*qtr;
			run(hfline, r - hfline, c);
		}//4사분면
		else {
			//cout << "4사분면 방문\n";
			sum += 3*qtr;
			run(hfline, r - hfline, c - hfline);
		}
	}	
}

void solve() {

	cin >> N;
	int line = pow(2, N);
	int r, c;
	cin >> r >> c;

	run(line, r, c);

	cout << sum;
}

int main() {
	init();
	solve();
}
