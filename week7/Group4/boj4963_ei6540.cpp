#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int w, h = 0;
int board[50][50];
bool visited[50][50];
int cnt;
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void dfs(int x, int y) {

	//정점 방문했다고 기록
	visited[x][y] = true;

	//다른 정점 확인
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			if (board[nx][ny] && !visited[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}

}

void solve() {

	while (cin >> w) {
		
		//종료조건
		cin >> h;
		if (w == 0 && h == 0) break;

		//입력
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}

		//초기화
		cnt = 0;
		memset(visited, false, sizeof(visited));

		//dfs 호출
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] && !visited[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << '\n';
	}
	return;
}

int main() {
	fastIO();
	solve();
}

