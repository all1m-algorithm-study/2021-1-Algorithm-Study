#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;
int num[2] = { 0 };
int arr[129][129];

int nan(int startX, int startY, int len) {
	int su = arr[startX][startY];
	if (len > 1) {
		for (int i = startY; i < startY + len; i++) {
			for (int m = startX; m < startX + len; m++) {
				if (arr[m][i] != su) {
					nan(startX, startY, len / 2);
					nan(startX, startY + len / 2, len / 2);
					nan(startX + len / 2, startY, len / 2);
					nan(startX + len / 2, startY + len / 2, len / 2);
					goto gogogo;
				}
			}
		}
		num[su]++;

	}
	else {
		num[su]++;

	}
gogogo:
	return 0;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		for (int m = 1; m <= a; m++) {
			cin >> arr[i][m];
		}
	}
	nan(1, 1, a);

	cout << num[0] << " " << num[1];



}