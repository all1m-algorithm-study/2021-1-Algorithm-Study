#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int devide_conquer(vector<vector<int>> &board, int row, int column, int offset) {
	if (offset == 1) {
		vector<int> set = { board[row][column], board[row + 1][column], board[row][column + 1], board[row + 1][column + 1] };
		sort(set.begin(), set.end());
		return set[2];
	}
	int a, b, c, d;
	a = devide_conquer(board, row, column, offset / 2);
	b = devide_conquer(board, row + offset, column, offset / 2);
	c = devide_conquer(board, row, column + offset, offset / 2);
	d = devide_conquer(board, row + offset, column + offset, offset / 2);

	vector<int>set = { a, b, c, d };
	sort(set.begin(), set.end());
	return set[2];
}

void solve() {
	int N;
	cin >> N;

	vector<vector<int>> board(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	cout << devide_conquer(board, 0, 0, N / 2);
}

int main() {
	init();
	solve();
}
