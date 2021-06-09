/*
* 1. 방문하지 않고 1인 지점에서 탐색을 시작한다.
* 2. 시작점에서 이동할 수 있는 모든 경로에 대해 BFS 탐색을 시작한다.
* 3. 경로를 이동할 때마다 방문했음을 표시한다.
*
* 시간복잡도 = O(t * m * n) (t : 테스트 케이스 수, m: 세로, n: 가로)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n, k;
int direction[2][4] = { {-1,1,0,0},{0,0,-1,1} };

void bfs(vector<vector<int>>& field, vector<vector<bool>>& visited, int start_x, int start_y) {
	queue<pair<int, int>> q;

	visited[start_x][start_y] = true;
	q.push(make_pair(start_x, start_y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + direction[0][i];
			int next_y = y + direction[1][i];

			if (!(next_x >= 0 && next_x < m) || !(next_y >= 0 && next_y < n) || visited[next_x][next_y]) continue;

			visited[next_x][next_y] = true;
			if (field[next_x][next_y] == 1) q.push(make_pair(next_x, next_y));
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int x, y;
		int cnt = 0;

		cin >> m >> n >> k;

		vector<vector<int>> field(m, vector<int>(n, 0));
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			field[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && field[i][j] == 1) {
					bfs(field, visited, i, j);
					cnt += 1;
				}
			}
		}
		cout << cnt << '\n';
	}
}
