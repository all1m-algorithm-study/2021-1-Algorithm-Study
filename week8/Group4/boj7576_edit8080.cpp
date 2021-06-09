/*
* 1. 초기 지점 모두를 큐에 넣고 BFS 탐색 시작 (동일한 레벨 탐색이 필요하므로)
* 2. BFS 탐색 마다 방문한 지점 표기
* 3. BFS 탐색 종료 후 방문하지 않은 지점이 있는지 확인
*
* 시간복잡도 = O(m*n) (m: 박스 가로, n: 박스 세로)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tomato {
	int x;
	int y;
	int day;
};

int m, n;
int max_day = 0;
int direction[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
vector<vector<int>> box;
vector<vector<bool>> visited;

void bfs(queue<tomato>& q) {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int day = q.front().day;
		q.pop();

		max_day = max(max_day, day);

		for (int i = 0; i < 4; i++) {
			int next_x = x + direction[0][i];
			int next_y = y + direction[1][i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				if (!visited[next_x][next_y] && box[next_x][next_y] == 0) {
					visited[next_x][next_y] = true;
					q.push({ next_x, next_y, day + 1 });
				}
			}
		}
	}
}
int main() {
	bool all_clear = true;
	queue<tomato> q;

	cin >> m >> n;
	box.resize(n, vector<int>(m, 0));
	visited.resize(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> box[i][j];

	// 초기 지점 설정
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && box[i][j] == 1) {
				visited[i][j] = true;
				q.push({ i, j, 0 });
			}
		}
	}
	bfs(q);

	// 통과 안된 부분 검출
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j] && box[i][j] != -1) all_clear = false;

	cout << (all_clear ? max_day : -1);
}
