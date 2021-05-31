#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int white = 0;
int blue = 0;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void devide_conquer(vector<vector<int>> &board, int row, int column, int range) {

	if (range != 1) {
		for (int i = 0; i < range; i++) {
			for (int j = 0; j < range; j++) {
				if (board[row][column] != board[row + i][column + j]) {
					devide_conquer(board, row, column, range / 2);
					devide_conquer(board, row + range / 2, column, range / 2);
					devide_conquer(board, row, column + range / 2, range / 2);
					devide_conquer(board, row + range / 2, column + range / 2, range / 2);
					return;
				}
			}
		}	
	}

	if (board[row][column] == 0) white++;
	else blue++;
	
	return;

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

	devide_conquer(board, 0, 0, N);

	cout << white << '\n' << blue;

}

int main() {
	init();
	solve();
}
