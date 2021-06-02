/*
* 1. 첫 줄(바깥쪽)을 기준으로 DFS를 탐색한다.
* 2. 안쪽에 대해 visited 배열을 확인하여 도달했다면 is_inner에 true를 저장한다.
* 3. 모든 바깥쪽 기준점을 탐색하는 동안 안쪽에 도달하지 못한다면 is_inner에 false가 유지된다.
* 
* 시간복잡도 = O(n^2) (n = 가로,세로 길이)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<string> grid;
vector<vector<bool>> visited;
int direction[2][4] = { {-1,1,0,0}, {0,0,-1,1} };

void dfs(int x, int y, int m, int n) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = x + direction[0][i];
		int next_y = y + direction[1][i];

		if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
			if (!visited[next_x][next_y] && grid[next_x][next_y] == '0')
				dfs(next_x, next_y, m, n);		
	}
}
bool inner_check(int m, int n) {
	for (int i = 0; i < n; i++)
		if (visited[m - 1][i]) return true;
	return false;
}

int main(){
	int m, n;
	string input;
	bool is_inner = false;
	cin >> m >> n;

	visited.resize(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++) {
		cin >> input;
		grid.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		if (!visited[0][i] && grid[0][i] == '0') {
			visited.resize(m, vector<bool>(n, false));
			dfs(0, i, m, n);

			is_inner = inner_check(m, n);
			if (is_inner) break;
		}
	}

	cout << (is_inner ? "YES" : "NO");
}
