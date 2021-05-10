#include <iostream>
#include <algorithm>
using namespace std;

bool arr[257][257];
int colorCnt[2];

void divNcnt(int x, int y, int size) {
	if (size == 1) {
		colorCnt[arr[x][y]]++;
		return;
	}

	int forCheck = 0;
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			forCheck += arr[i][j];

	if (forCheck == size*size) {
		colorCnt[1]++;
		return;
	}
	else if (forCheck == 0) {
		colorCnt[0]++;
		return;
	}

	divNcnt(x, y, size / 2);
	divNcnt((x + x + size) / 2, y, size / 2);
	divNcnt(x, (y + y + size) / 2, size / 2);
	divNcnt((x + x + size) / 2, (y + y + size) / 2, size / 2);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	divNcnt(1, 1, n);
	cout << colorCnt[0] << endl << colorCnt[1];
}