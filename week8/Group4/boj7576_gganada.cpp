#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

void bfs(int(&map)[1002][1002], bool(&check)[1002][1002], queue<tuple<int, int, int>>(&q)) {
	int len = get<2>(q.front()) + 1;
	int a, b;
	a = get<0>(q.front());
	b = get<1>(q.front());
	if ((!map[a - 1][b]) && (!check[a - 1][b])) {
		check[a - 1][b] = 1;
		q.push(tuple<int, int, int>(a - 1, b, len));
	}
	if ((!map[a + 1][b]) && (!check[a + 1][b])) {
		check[a + 1][b] = 1;
		q.push(tuple<int, int, int>(a + 1, b, len));
	}
	if ((!map[a][b - 1]) && (!check[a][b - 1])) {
		check[a][b - 1] = 1;
		q.push(tuple<int, int, int>(a, b - 1, len));
	}
	if ((!map[a][b + 1]) && (!check[a][b + 1])) {
		check[a][b + 1] = 1;
		q.push(tuple<int, int, int>(a, b + 1, len));
	}
	q.pop();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int map[1002][1002] = { 1 };
	int m, n, len = 0, num = 0;
	bool check[1002][1002] = { 0 };
	queue<tuple<int, int, int>> q;
	bool can = 1;

	for (int i = 0; i < 1002; i++) {
		for (int j = 0; j < 1002; j++) {
			map[i][j] = 1;
		}
	}

	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			cin >> map[i][j];
			if (map[i][j] == 1) {
				check[i][j] = 1;
				q.push(tuple<int, int, int>(i, j, 0));
			}
		}
	}

	while (q.size()) {

		len = get<2>(q.front());
		bfs(map, check, q);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (!check[i][j] && !map[i][j]) {
				can = 0;

			}
		}

	}
	if (can == 0) len = -1;

	cout << len;

}