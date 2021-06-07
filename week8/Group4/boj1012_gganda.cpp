#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include<queue>
#include<vector>
using namespace std;

void count(bool(&map)[52][52], int(&num), int i, int j) {
	map[i][j] = 0;


	if (map[i - 1][j]) count(map, num, i - 1, j);
	if (map[i + 1][j]) count(map, num, i + 1, j);
	if (map[i][j - 1]) count(map, num, i, j - 1);
	if (map[i][j + 1]) count(map, num, i, j + 1);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool map[52][52] = { 0 };

	int num = 0, t, n, m, nu;
	int imsi1, imsi2;


	cin >> t;
	for (int k = 0; k < t; k++) {

		num = 0;


		cin >> n >> m >> nu;
		for (int i = 0; i < nu; i++) {
			cin >> imsi1 >> imsi2;
			map[imsi1 + 1][imsi2 + 1] = 1;
		}


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

				if (map[i][j]) {
					map[i][j] = 0;
					num++;


					if (map[i - 1][j]) count(map, num, i - 1, j);
					if (map[i + 1][j]) count(map, num, i + 1, j);
					if (map[i][j - 1]) count(map, num, i, j - 1);
					if (map[i][j + 1]) count(map, num, i, j + 1);
				}

			}
		}




		cout << num << "\n";

	}


}