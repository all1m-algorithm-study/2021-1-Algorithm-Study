#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int N;
	cin >> N;
	stack<int> s;
	queue<int> q;
	int now = 1;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}
	
	while (!q.empty()) {
		int current = q.front();
		
		//순서에 맞는 학생을 찾은 경우
		if (current == now) {
			q.pop();
			now++;
		}
		//학생이 없으면
		else {
			//스택을 먼저 확인
			if (!s.empty() && s.top() == now) {
				s.pop();
				now++;
			}
			//스택에도 없으면 줄 서있던 학생을 스택에 넣음
			else {
				s.push(current);
				q.pop();
			}
		}
	}

	//스택에만 학생이 남아 있을때 순서 확인
	while (!s.empty()) {
		int current = s.top();
		s.pop();
		if (current != now) {
			cout << "Sad\n";
			return;
		}
		now++;
	}

	cout << "Nice\n";
	return;


}

int main() {
	fastIO();
	solve();
}

