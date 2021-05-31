/*
* 1. BFS를 통해 트리 구조를 탐색한다.
* 2. BFS의 현재 기준 노드와 다음 탐색할 노드를 통해 부모, 자식 관계를 식별한다.
*
* 시간복잡도 = O(V+E) (V : 정점 , E : 간선)
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> parent;

void bfs(int n, int current) {
	int next_node;
	queue<int> next_set;
	visited[current] = true;
	
	for (int i = 0; i < (int)tree[current].size(); i++) {
		next_node = tree[current][i];
		next_set.push(next_node);		
	}
	while (!next_set.empty()) {
		next_node = next_set.front();
		next_set.pop();
		
		if (!visited[next_node]) {
			parent[next_node] = current;
			bfs(n, next_node);
		}
	}
	return;
}
int main(){
	int n;
	int v1, v2;	
	
	cin >> n;
	tree.resize(n+1);
	visited.resize(n+1, false);
	parent.resize(n+1);
	
	for (int i = 0; i < n - 1; i++) {
		cin >> v1 >> v2;
		tree[v1].push_back(v2);
		tree[v2].push_back(v1);
	}

	bfs(n, 1);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';   
}
