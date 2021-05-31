#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
const int MAX = 100+1;

int board[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int min_v = 101; int max_v = 0;
int tmp_safearea;
int max_safearea = 0;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void dfs(int x, int y, int flooding) {

	visited[x][y] = true;

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (!visited[nx][ny] && board[nx][ny] > flooding) {
				dfs(nx, ny, flooding);
			}
		}
	}
}

void solve() {
	cin >> N;

	//graph input
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] > max_v) {
				max_v = board[i][j];
			}
			else if (board[i][j] < min_v) {
				min_v = board[i][j];
			}
		}
	}
	
	// 비 양이 min_v ~ max_v일 때 각각 dfs 돌려 안전영역 개수 찾음
	for (int i = min_v; max_v >= i; i++) {

		memset(visited, false, sizeof(visited));
		tmp_safearea = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (board[j][k] > i && !visited[j][k]) {
					tmp_safearea++;
					dfs(j, k, i);
				}
			}
		}
		if (tmp_safearea > max_safearea) max_safearea = tmp_safearea;
	}
	if (min_v == max_v) cout << "1";
	else cout << max_safearea;
}

int main() {
	fastIO();
	solve();
}

