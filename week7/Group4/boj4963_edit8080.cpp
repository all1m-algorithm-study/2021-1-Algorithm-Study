/*
* 1. 상, 하, 좌, 우, 대각선 방향 설정
* 2. 방문하지 않은 지점에서 시작 (cnt += 1)
* 3. 다음 방향으로 이동하는 지점이 방문하지 않은 점이고 땅(1)이라면 이동 -> 방문점 찍기
*
* 시간복잡도 = O(n^2)  (n = 너비, 높이) -> 모든 지점에서 탐색 시작
*/

#include <iostream>
#include <vector>

using namespace std;

int direction[2][8] = { {-1, 1, 0, 0, -1, -1, 1, 1}, {0, 0, -1 ,1, -1, 1, -1, 1} };

void dfs(int (*map)[50], bool (*visited)[50], int w, int h, int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int next_x = x + direction[0][i];
		int next_y = y + direction[1][i];

		if (next_x >= 0 && next_x < h && next_y >= 0 && next_y < w) 
			if(!visited[next_x][next_y] && map[next_x][next_y] == 1)
				dfs(map, visited, w, h, next_x, next_y);		
	}
	return;
}

int main(){
	while (true) {
		int w, h;
		int cnt = 0;
		int map[50][50];
		bool visited[50][50] = { false };

		cin >> w >> h;

		if (w == 0 && h == 0)
			break;
				
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++) 
				cin >> map[i][j];
			
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					dfs(map, visited, w, h, i, j);
					cnt += 1;
				}
			}
		}
		cout << cnt << '\n';
	}
}
