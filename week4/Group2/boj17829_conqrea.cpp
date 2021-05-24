#include <iostream>
#include <algorithm>
using namespace std;

int arr[1025][1025];

int divNsec(int x, int y, int size) {
	if (size == 1)
		return arr[x][y];
	int sx = x, sy = y, mx = (x + x + size) / 2, my = (y + y + size) / 2;
	int sortedNum[4] = {
		divNsec(sx,sy,size / 2),
		divNsec(sx,my,size / 2),
		divNsec(mx,sy,size / 2),
		divNsec(mx,my,size / 2)
	};
	sort(sortedNum, sortedNum + 4);
	return sortedNum[2];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	cout << divNsec(1, 1, n);
}