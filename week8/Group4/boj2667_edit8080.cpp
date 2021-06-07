/*
* 1. 방문하지 않은 점에서 BFS 탐색을 시작한다.
* 2. BFS 탐색을 돌면서 이동한 점의 방문을 표시하고 방문 지점의 개수를 1개씩 센다.
* 3. 반환된 값을 오름차순으로 정렬 후 출력한다.
*
* 시간복잡도 = O(n^2) (n: 한 변의 크기)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int direction[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
vector<string> map;
vector<vector<bool>> visited;
vector<int> house;

int bfs(int start_x, int start_y) {
	int cnt = 1;
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

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
				if (!visited[next_x][next_y] && map[next_x][next_y] == '1') {
					cnt += 1;
					visited[next_x][next_y] = true;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin >> n;

	map.resize(n);
	visited.resize(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
		cin >> map[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && map[i][j] == '1')
				house.push_back(bfs(i, j));

	sort(house.begin(), house.end());

	cout << (int)house.size() << '\n';
	for (int i = 0; i < (int)house.size(); i++)
		cout << house[i] << '\n';
}
