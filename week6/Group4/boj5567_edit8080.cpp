/*
* 1. 그래프를 구성한다.
* 2. BFS를 2번 수행한다.
* 3. 2번 수행후 방문한 노드의 개수를 센다.
* 
* 시간복잡도 = O(V+E) (노드 방문 + 간선 방문)
*/

#include <iostream>
#include <vector>
#include <queue>

#define SIZE 10001
using namespace std;

int invite(vector<vector<int>> &edge, vector<bool> &visited, int n, int x) {
	queue<int> q;
	int ret = 0;

	// BFS 1단계 수행
	for (int i = 0; i < (int)edge[x].size(); i++) {
		q.push(edge[x][i]);
		visited[edge[x][i]] = true;
	}

	// BFS 2단계 수행
	while (!q.empty()) {
		int front = q.front();
		
		for (int i = 0; i < (int)edge[front].size(); i++)
			visited[edge[front][i]] = true;
		
		q.pop();
	}

	for (int i = 2; i <= n; i++)
		if (visited[i]) ret += 1;

	return ret;
}

int main(){
	int n, m;
	vector<vector<int>> edge;
	vector<bool> visited(SIZE, false);

	edge.resize(SIZE);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	cout << invite(edge, visited, n, 1);	
}
