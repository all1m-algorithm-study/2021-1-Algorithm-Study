#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void run(int start, int end, vector<char> &line) {

	if (end - start == 1) return;
	for (int i = (end - start) / 3 + start; i < 2 * (end - start) / 3 + start; i++) {
		line[i] = ' ';
	}
	run(start, (end - start) / 3 + start, line);
	run(2 * (end - start) / 3 + start, end, line);
}
//0 1 2    3 4 5    6 7 8
void solve() {
	

	int N;
	while (cin >> N) {

		int end = pow(3, N);
		vector<char> line(end);

		for (int i = 0; i < end; i++) {
			line[i] = '-';
		}

		run(0, end, line);

		for (int i = 0; i < end; i++) {
			cout << line[i];
		}
		cout << '\n';
	}
	
}

int main() {
	init();
	solve();
}
