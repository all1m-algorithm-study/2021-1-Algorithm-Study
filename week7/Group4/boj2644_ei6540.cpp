#include <iostream>
#include <vector>

using namespace std;

int N, node1, node2, cnt;
int outcnt = 0;
const int MAX = 100+1;
bool visited[MAX];
vector<int> graph[MAX];
bool flag = false;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void dfs(int x, int cnt) {

	//대상으로 하는 노드를 찾음
	if (x == node2) {
		outcnt = cnt;
		flag = true;
		return;
	}

	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int nextnode = graph[x][i];
		if (!visited[nextnode]) {
			cnt++;
			dfs(nextnode, cnt);
			cnt--;
		}
	}
}

void solve() {
	cin >> N;
	cin >> node1 >> node2;

	//graph input
	int edge;
	cin >> edge;
	int tmp1, tmp2;
	for (int i = 0; i < edge; i++) {
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	//count
	cnt = 0;
	dfs(node1, cnt);

	//print
	if (flag) cout << outcnt;
	else cout << "-1";

}

int main() {
	fastIO();
	solve();
}


