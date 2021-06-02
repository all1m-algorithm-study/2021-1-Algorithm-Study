#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
bool visited[MAX];
vector<int> graph[MAX];
int parent[MAX];

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int nextnode = graph[x][i];
		if (!visited[nextnode]) {
			parent[nextnode] = x;
			dfs(nextnode);
		}
	}
}

void solve() {
	int N;
	cin >> N;
	int node1, node2;

	for (int i = 1; i < N; i++) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
}

int main() {
	fastIO();
	solve();
}

