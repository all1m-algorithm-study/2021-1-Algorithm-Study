#include <iostream>
#include <vector>

using namespace std;

int M, N;
const int MAX = 1000+1;
bool board[MAX][MAX];
bool visited[MAX][MAX];
bool flag = false;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void dfs(int x, int y) {

	//맨 아래까지 내려옴
	if (x == M-1) {
		flag = true;
		return;
	}

	visited[x][y] = true;

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N && !board[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

void solve() {
	cin >> M >> N;

	//graph input
	string s;
	for (int i = 0; i < M; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			board[i][j] = s[j] - '0';
		}
	}
	
	//count
	for (int i = 0; i < N; i++) {
		if (flag) break;
		else if (!board[0][i]&&!visited[0][i]) {
			dfs(0, i);
		}
	}

	//print
	if (flag) cout << "YES";
	else cout << "NO";

}

int main() {
	fastIO();
	solve();
}

