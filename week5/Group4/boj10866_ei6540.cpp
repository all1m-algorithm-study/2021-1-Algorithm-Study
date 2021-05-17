#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 10000;
int dq[2 * MAX + 1] = { 0 };

void fast_io() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int solve() {

	int head = MAX;
	int tail = MAX;

	int N;
	cin >> N;

	while (N--) {
		string str;
		cin >> str;
		if (str=="push_front") {
			cin >> dq[--head];
		}
		else if (str=="push_back") {
			cin >> dq[tail++];
		}
		else if (str=="pop_front") {
			//사이즈0인지 먼저 검사
			if (head != tail) cout << dq[head++] << '\n';
			else cout << "-1\n";
		}
		else if (str=="pop_back") {
			//사이즈0인지 먼저 검사
			if (head != tail) cout << dq[--tail] << '\n';
			else cout << "-1\n";
		}
		else if (str=="size") {
			cout << tail - head << '\n';
		}
		else if (str=="empty") {
			if (head != tail) cout << "0\n";
			else cout << "1\n";
		}
		else if (str== "front") {
			if (head != tail) cout << dq[head] << '\n';
			else cout << "-1\n";
		}
		else if (str== "back") {
			if (head != tail) cout << dq[tail-1] << '\n';
			else cout << "-1\n";
		}
	}
	return 0;
}




int main() {
	fast_io();
	solve();
}
