#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

bool visit[1001] = { false, };
vector<int> graph[1001];
queue<int> q;
int N, M;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
/*
void dfs(int now_node) {
	// 종료조건 visit
	visit[now_node] = true;

	// 현재 노드 출력
	cout << now_node <<" ";
	
	// now_node와 근접한 노드 순회
	for (int i : graph[now_node]) {
		//근접 노드에 방문한 적 없다면 재귀호출
		if (!visit[i]) {
			dfs(i);
		}
	}
}
*/
void bfs(int now_node) {
	q.push(now_node);
	visit[now_node] = true;
	
	// 큐가 빌 때까지 방문
	while (!q.empty()) {
		int next_node = q.front();
		q.pop();

		for (int i : graph[next_node]) {
			// 방문하지 않은 곳이 있다면 예약
			if (!visit[i]) {
				q.push(i);
				visit[i] = true;
			}
		}
	}
}

void solve() {
	cin >> N >> M;
	
	int node_1, node_2;

	for (int i = 0; i < M; i++) {
		cin >> node_1 >> node_2;
		graph[node_1].push_back(node_2);
		graph[node_2].push_back(node_1);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			bfs(i);
			cnt++;
		}
	}

	cout << cnt;
}

int main() {
	init();
	solve();
}

