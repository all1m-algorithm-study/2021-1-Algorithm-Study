#include <iostream>
using namespace std;

int JangGiPan[40][40], dir[8][2] = { {0, 1}, {1, 0}, {1, 1}, {-1, 1} };

int CheckFiveMok(int color, int dirI, int x, int y) {
	if (JangGiPan[x - dir[dirI][0]][y - dir[dirI][1]] == color)
		return 0;
	bool isLeastFive = true;
	for (int i = 1; i <= 4; i++) {
		if (JangGiPan[x + dir[dirI][0] * i][y + dir[dirI][1] * i] != color || x + dir[dirI][0] * i < 1 || x + dir[dirI][0] * i > 19 || y + dir[dirI][1] * i < 1 || y + dir[dirI][1] * i > 19) {
			isLeastFive = false;
			break;
		}
	}
	if (isLeastFive && JangGiPan[x + dir[dirI][0] * 5][y + dir[dirI][1] * 5] != color) {
		return color;
	}
	return 0;
}

int main()
{
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> JangGiPan[i][j];
		}
	}

	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			for (int k = 0; k < 4; k++) {
				int res = CheckFiveMok(JangGiPan[i][j], k, i, j);
				if (res != 0) {
					cout << JangGiPan[i][j] << endl << i << " " << j;
					return 0;
				}
			}
		}
	}
	cout << 0;
}