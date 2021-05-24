/*
* 1. 대칭 그래프를 구성한다.
* 2. 방문한 지점을 체크한다.
* 3. 기준 노드에서 이어져 있는 간선이 존재하고 방문하지 않았다면 해당 노드를 기준으로 재귀적으로 탐색 함수를 호출한다.
* 
* 시간복잡도 = O(V+E) (노드 방문 + 간선 방문)
*/
#include <iostream>
#include <vector>

#define SIZE 101

using namespace std;

void virus(vector<vector<int>> &computers, vector<bool> &visited, int x, int n) {
	visited[x] = true;

	for (int i = 1; i <= n; i++) {
		if (computers[x][i] != 0 && !visited[i]) {
			virus(computers, visited, i, n);
		}
	}
	return;
}

int main(){
	int n, t;
	vector<vector<int>> computers(SIZE, vector<int>(SIZE, 0));
	vector<bool> visited(SIZE, false);
	int cnt = 0;

	cin >> n >> t;

	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		computers[x][y] = 1;
		computers[y][x] = 1;
	}
	
	virus(computers, visited, 1, n);
	
	for (int i = 2; i <= n; i++)
		if (visited[i]) cnt += 1;

	cout << cnt;
}
