/*
* 1. �ִ� �Ÿ� Ž���� ���� BFS Ž���� �����Ѵ�.
* 2. ���� �μ��� ���� �μ��� �ʴ� ��츦 ������.
* 3. �������� ������ ������ cnt ���� 1�� ������Ų �� ���ް����ϸ� cnt��, �������� ���ϸ� -1�� return�Ѵ�.
*
* ����) ���� �μ��� ���� �μ��� �ʴ� ��쿡 ���� �湮ǥ�ø� ���� ���־���� (���� ��ġ�� ���� ��)
*
* �ð����⵵ = O(n*m) (n: ������ ����, m: ������ ����)
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
				// ���� �μ��� �ʴ� ��� (�̹� �� �� �μ� ���� �湮 ǥ�ø� ���� ����)
				if (!visited[next_x][next_y][(int)break_wall] && map[next_x][next_y] == '0') {
					visited[next_x][next_y][(int)break_wall] = true;
					q.push({ next_x, next_y, cnt + 1, break_wall });
				}
				// ���� �μ��� ���
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
