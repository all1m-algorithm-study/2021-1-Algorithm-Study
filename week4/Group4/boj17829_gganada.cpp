#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>



using namespace std;

int get(int a[4]) {
	sort(a, a + 4);
	return a[2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a[1025][1025];
	int b;

	cin >> b;
	for (int i = 0; i < b; i++) {
		for (int l = 0; l < b; l++) {
			cin >> a[i + 1][l + 1];
		}
	}
	int c[4];
	for (int m = 1; pow(2, m) <= b; m++) {
		for (int i = 0; i < b / pow(2, m); i++) {
			for (int l = 0; l < b / pow(2, m); l++) {
				c[0] = a[2 * i + 1][2 * l + 1];
				c[1] = a[2 * i + 2][2 * l + 1];
				c[2] = a[2 * i + 1][2 * l + 2];
				c[3] = a[2 * i + 2][2 * l + 2];
				a[1 + i][1 + l] = get(c);

			}
		}
	}
	cout << a[1][1];
}