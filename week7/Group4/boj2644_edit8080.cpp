/*
* 1. 친척 그래프 생성
* 2. DFS를 통해 친척 관계 탐색
* 3. visited 배열에 계산한 촌수를 표시
* 
* O(V+E) (V: 정점, E: 간선)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> relative;
vector<int> visited;

void dfs(int current, int end, int count) {
	visited[current] = count;

	if (current == end)
		return;	

	for (int i = 0; i < (int)relative[current].size(); i++) {
		int next_node = relative[current][i];
		if (visited[next_node] == -1)
			dfs(next_node, end, count+1);
	}
}

int main() {
	int n;
	int v1, v2;
	int m;
	int x, y;

	cin >> n >> v1 >> v2 >> m;

	relative.resize(n + 1);
	visited.resize(n + 1, -1);

	while (m--) {
		cin >> x >> y;
		relative[x].push_back(y);
		relative[y].push_back(x);
	}
	dfs(v1, v2, 0);
	cout << visited[v2];
}
