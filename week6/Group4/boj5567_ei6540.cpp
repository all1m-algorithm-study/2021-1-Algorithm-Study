#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

bool visit[501] = { false, };
vector<int> graph[501];
queue<int> q;
int N, M;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


void solve() {
	cin >> N >> M;
	
	int node_1, node_2;
	for (int i = 0; i < M; i++) {
		cin >> node_1 >> node_2;
		graph[node_1].push_back(node_2);
		graph[node_2].push_back(node_1);
	}
	
	//친구
	for (int i = 0; i < graph[1].size(); i++) {
		q.push(graph[1][i]);
		visit[graph[1][i]] = true;
	}

	//친구의 친구
	while (!q.empty()) {
		int ff = q.front();
		q.pop();
		for (int i = 0; i < graph[ff].size(); i++) {
			if (!visit[graph[ff][i]]) {
				visit[graph[ff][i]] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 501; i++) {
		cnt += visit[i] ? 1 : 0;
	}

	cout << cnt-1;

}

int main() {
	init();
	solve();
}

