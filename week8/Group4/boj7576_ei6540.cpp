#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
const int MAX = 1000 + 1;
int board[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

queue<pair<int, int>> q;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	cin >> N >> M;

	//graph input
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i, j });
			}
			else if (board[i][j] == -1) {
				visited[i][j] = true;
			}
		}
	}

	int days = 0;
	while (!q.empty()) {

		int qsize = q.size();

		for (int i = 0; i < qsize; i++) {

			int first = q.front().first;
			int second = q.front().second;
			visited[first][second] = true;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = first + dx[j];
				int ny = second + dy[j];

				if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
					if (!visited[nx][ny] && board[nx][ny] == 0) {
						board[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		days++;
	}

	// false가 있으면 -1
	bool flag = false;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				cout << "-1";
				return;
			}
		}
	}

	// 그렇지 않으면 day
	cout << days - 1;

}

int main() {
	fastIO();
	solve();
}

