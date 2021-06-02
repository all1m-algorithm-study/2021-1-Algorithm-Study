/*
* 1. 대칭 그래프를 구성한다.
* 2. 방문한 지점을 체크한다.
* 3. 기준 노드에서 이어져 있는 간선이 존재하고 방문하지 않았다면 해당 노드를 기준으로 재귀적으로 탐색 함수를 호출한다.
* 4. 방문하지 않은 지점이 있다면 또다른 연결 요소이므로 cnt를 1 증가시키고 2~3과정을 반복한다.
* 
* 시간복잡도 = O(V+E) (노드 방문 + 간선 방문)
*/
#include <iostream>
#include <vector>

#define SIZE 1001

using namespace std;

void search(vector<vector<int>> &edge, vector<bool> &visited, int n, int x) {
	visited[x] = true;

	for (int i = 1; i <= n; i++) {
		if (!visited[i] && edge[x][i] != 0) {
			search(edge, visited, n, i);
		}		
	}
	return;
}

int main(){
	int n, m;
	vector<vector<int>> edge(SIZE, vector<int>(SIZE, 0));
	vector<bool> visited(SIZE, false);
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edge[x][y] = 1;
		edge[y][x] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			search(edge, visited, n, i);
			cnt += 1;
		}
	}
	cout << cnt;
}
