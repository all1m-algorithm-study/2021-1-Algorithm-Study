/*
* 1. 빙하의 덩어리를 DFS를 통해 판별한다.
* 2. 탐색 후 빙하가 두 덩어리가 아니라면 바다에 인접한 빙하들이 녹는 상황을 적용한다.
* 3. 빙하가 두 덩어리가 될 때까지 1~2과정을 반복한다.
* 
* 시간복잡도 = O(n^2)
*/

#include <iostream>
#include <vector>

using namespace std;

int n, m;
int direction[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

// 경계 판별
bool in_bound(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}

// 빙하 영역 탐색
void dfs(vector<vector<int>> &area, vector<vector<bool>> &visited, int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = x + direction[0][i];
		int next_y = y + direction[1][i];

		if (in_bound(next_x, next_y) && !visited[next_x][next_y] && area[next_x][next_y] > 0)
			dfs(area, visited, next_x, next_y);
	}
}

// 빙하 영역의 갯수
int ice_cnt(vector<vector<int>> &area){
	int ret = 0;
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && area[i][j] > 0) {
				dfs(area, visited, i, j);
				ret += 1;
			}
		}
	}
	return ret;
}

int main(){	
	int year = 0;
	int ice;
	bool all_melt = true;
	vector<vector<int>> area;
	cin >> n >> m;

	area.resize(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> area[i][j];
		
	while (true){
		ice = ice_cnt(area);

		if (ice >= 2)
			break;

		// 빙하 녹이기
		year += 1;		
		vector<vector<int>> melt;
		melt.resize(n, vector<int>(m, 0));
		all_melt = true;

		// 1) 빙하가 녹을 정도를 계산
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < 4; k++) {					
					int next_i = i + direction[0][k];
					int next_j = j + direction[1][k];
						
					if (in_bound(next_i, next_j) && area[next_i][next_j] <= 0)
						melt[i][j] += 1;
				}
			}
		}
		// 2) 빙하가 녹고난 상태
		for (int i = 0; i < n;i++) {
			for (int j = 0; j < m; j++) {
				area[i][j] -= melt[i][j];
				if (area[i][j] > 0)
					all_melt = false;
			}
		}

		// 3) 다 녹은 경우
		if (all_melt)
			break;	
	} 

	cout << (all_melt ? 0 : year);
}
