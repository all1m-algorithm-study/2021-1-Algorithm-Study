#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N;
const int MAX = 25 + 1;
bool board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> v;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int bfs(int x, int y) {

	int ans = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	ans++;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (board[nx][ny] && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
					ans++;
				}
			}
		}
	}
	return ans;
}

void solve() {
	cin >> N;

	//graph input
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			board[i][j] = s[j] - '0';
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] && !visited[i][j]) {
				v.push_back(bfs(i, j));			
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}

int main() {
	fastIO();
	solve();
}

