#include <iostream>
#include <queue>
using namespace std;

int n, net[101][101], v[101], cnt = 0;

void bfs(int s) {
	queue<int> q;
	q.push(s);
	v[s] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (net[t][i] && !v[i])
			{
				cnt++;
				q.push(i);
				v[i] = 1;
			}
		}
	}
}

int main()
{
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		net[a][b] = net[b][a] = 1;
	}

	bfs(1);

	cout << cnt;
}