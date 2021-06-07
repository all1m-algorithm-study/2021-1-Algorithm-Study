/*
* 1. 탐색 큐에 불을 먼저 넣어 동시 접근 여부를 체크한다. (불과 지훈이 동일하게 이동할 경우 지훈이 이동할 수 없음)
* 2. 불이 이동할 경우 방문 여부 체크와 이동할 수 있는 경로를 불로 표시한다.('.' → 'F')
* 3. 지훈이 이동할 경우 방문 여부 체크를 체크한다.
*
* 시간복잡도 = O(r*c) (r: 세로의 크기, c : 가로의 크기)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct maze_move {
	char type;
	int x;
	int y;
	int cnt;
};

int r, c;
int direction[2][4] = { {-1,1,0,0},{0,0,-1,1} };
vector<string> maze;
vector<vector<bool>> visited;
vector<vector<bool>> fire_visited;

int bfs(int start_x, int start_y, queue<maze_move>& q) {
	q.push({ 'J', start_x, start_y, 1 });

	while (!q.empty()) {
		char type = q.front().type;
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		if (type == 'J' && (x == 0 || x == r - 1 || y == 0 || y == c - 1)) return cnt;

		for (int i = 0; i < 4; i++) {
			int next_x = x + direction[0][i];
			int next_y = y + direction[1][i];

			if (next_x >= 0 && next_x < r && next_y >= 0 && next_y < c) {
				// 1. 지훈 이동
				if (type == 'J') {
					if (!visited[next_x][next_y] && maze[next_x][next_y] == '.') {
						visited[next_x][next_y] = true;
						q.push({ 'J', next_x, next_y, cnt + 1 });
					}
				}
				// 2. 불 이동
				else if (type == 'F') {
					if (!fire_visited[next_x][next_y] && maze[next_x][next_y] != '#') {
						maze[next_x][next_y] = 'F';
						fire_visited[next_x][next_y] = true;
						q.push({ 'F', next_x, next_y, cnt + 1 });
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	int start_x, start_y;
	int result;
	queue<maze_move> q;

	cin >> r >> c;

	maze.resize(r);
	visited.resize(r, vector<bool>(c, false));
	fire_visited.resize(r, vector<bool>(c, false));

	for (int i = 0; i < r; i++)
		cin >> maze[i];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (maze[i][j] == 'J') {
				start_x = i; start_y = j;
				visited[start_x][start_y] = true;
			}
			if (maze[i][j] == 'F') {
				q.push({ 'F', i, j, 1 });
				fire_visited[i][j] = true;
			}
		}
	}

	result = bfs(start_x, start_y, q);

	if (result == -1)
		cout << "IMPOSSIBLE";
	else
		cout << result;
}
