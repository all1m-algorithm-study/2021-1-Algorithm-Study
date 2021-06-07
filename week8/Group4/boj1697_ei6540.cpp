#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int subin, sister;
const int MAX = 100000 + 1;
bool board[MAX] = { 0, };
bool visited[MAX];
int time_[MAX] = { 0, };
vector<int> v;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	cin >> subin >> sister;
	queue<int> q;
	q.push(subin);
	visited[subin] = true;
	time_[subin] = 0;
	int ans = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		visited[now] = true;

		// 수빈이가 동생을 찾음
		if (now == sister) {
			ans = time_[now];
			break;
		}

		// 수빈이가 한걸음 앞으로
		if (now + 1 < MAX && !visited[now + 1]) {
			time_[now + 1] = time_[now] + 1;
			visited[now+1] = true;
			q.push(now + 1);
		}

		// 수빈이가 한걸음 뒤로
		if (now - 1 >= 0 && !visited[now - 1]) {
			time_[now - 1] = time_[now] + 1;
			visited[now-1] = true;
			q.push(now - 1);
		}

		// 수빈이가 순간이동
		if (now*2<MAX && !visited[now*2]) {
			time_[now*2] = time_[now] + 1;
			visited[now*2] = true;
			q.push(now * 2);
		}
	}
	cout << ans;
}

int main() {
	fastIO();
	solve();
}

