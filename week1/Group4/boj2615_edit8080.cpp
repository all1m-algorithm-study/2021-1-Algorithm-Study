/*
* 1. 0이 아닌 모든 점에서 가로, 세로, 대각선 방향으로 동일한 숫자를 탐색한다. (++길이)
* 2. 길이가 5가 넘게 탐색이 진행되면 탐색을 종료한다.
* 3. 탐색이 종료될 때 길이가 5라면 진행한 방향에서 1칸 반대의 숫자를 확인한다.
* 3-1. 1칸 반대 숫자가 시작 숫자와 같으면 false를 리턴한다. (최소 6목)
* 3-2. 1칸 반대 숫자가 시작 숫자와 같으면 true를 리턴한다.
* 
* 시간복잡도 = O(n^2) (n: 게임판의 길이)
* 
*/

#include <iostream>

#define LEN 19
#define SIZE 21

int board[SIZE][SIZE] = { 0 };
int direction[4][2] = { {1, 0},{0, 1},{1, 1},{-1, 1} };
int nextCords[2];
int prevCords[2];

using namespace std;

bool isFive(int player, int *cords, int *direct, int *origin, int length) {
	nextCords[0] = cords[0] + direct[0]; 
	nextCords[1] = cords[1] + direct[1];

	prevCords[0] = origin[0] - direct[0];
	prevCords[1] = origin[1] - direct[1];

	if (length > 5)
		return false;
	
	if (player == board[nextCords[0]][nextCords[1]])
		return isFive(player, nextCords, direct, origin, ++length);
	else {
		if (length == 5)
			return player != board[prevCords[0]][prevCords[1]] ? true : false;

		else
			return false;
	}
}
bool loopBoard() {
	int player;
	int cords[2];
	int direct[2];

	for (int j = 1; j <= LEN; j++) {
		for (int i = 1; i <= LEN; i++) {		
			for (int k = 0; k < 4; k++) {
				player = board[i][j];
				cords[0] = i;
				cords[1] = j;
				direct[0] = direction[k][0];
				direct[1] = direction[k][1];				

				if (player != 0 && isFive(player, cords, direct, cords, 1)) {
					cout << player << '\n' << cords[0] << ' ' << cords[1];
					return true;
				}
			}
		}
	}
	return false;
}
int main() {
	for (int i = 1; i <= LEN; i++)
		for (int j = 1; j <= LEN; j++)
			cin >> board[i][j];

	if (!loopBoard())
		cout << "0";

	return 0;
}