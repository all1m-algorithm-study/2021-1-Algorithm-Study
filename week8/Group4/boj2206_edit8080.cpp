/*
* 1. 최단 거리 탐색을 위해 BFS 탐색을 수행한다.
* 2. 벽을 부수는 경우와 부수지 않는 경우를 나눈다.
* 3. 목적지에 도달할 때까지 cnt 값을 1씩 증가시킨 후 도달가능하면 cnt를, 도달하지 못하면 -1을 return한다.
*
* 주의) 벽을 부수는 경우와 부수지 않는 경우에 대한 방문표시를 따로 해주어야함 (동일 위치에 대한 비교)
*
* 시간복잡도 = O(n*m) (n: 세로의 길이, m: 가로의 길이)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct move_map {
	int x;
	int y;
	int cnt;
	bool break_wall;
};

int n, m;
int direction[2][4] = { {-1,1,0,0},{0,0,-1,1} };
vector<string> map;
vector<vector<vector<bool>>>visited;

int bfs(int start_x, int start_y) {
	queue<move_map> q;
	visited[start_x][start_y][0] = true;
	q.push({ start_x, start_y, 1, false });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		bool break_wall = q.front().break_wall;
		q.pop();

		if (x == n - 1 && y == m - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int next_x = x + direction[0][i];
			int next_y = y + direction[1][i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
				// 벽을 부수지 않는 경우 (이미 한 번 부순 경우는 방문 표시를 따로 수행)
				if (!visited[next_x][next_y][(int)break_wall] && map[next_x][next_y] == '0') {
					visited[next_x][next_y][(int)break_wall] = true;
					q.push({ next_x, next_y, cnt + 1, break_wall });
				}
				// 벽을 부수는 경우
				if (!break_wall && map[next_x][next_y] == '1')
					q.push({ next_x, next_y, cnt + 1, true });
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;

	map.resize(n);
	visited.resize(n, vector<vector<bool>>(m, vector<bool>(2, false)));

	for (int i = 0; i < n; i++)
		cin >> map[i];

	cout << bfs(0, 0);
}
