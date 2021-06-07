#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int M, N, K;
const int MAX = 50 + 1;
bool board[MAX][MAX] = { 0, };
bool visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> v;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void bfs(int x, int y) {

	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (board[nx][ny] && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	return;
}

void solve() {
	int T;
	cin >> T;

	while (T--) {
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}

		int ans = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] && !visited[i][j]) {
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';

	}

}

int main() {
	fastIO();
	solve();
}

