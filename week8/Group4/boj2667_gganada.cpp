#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include<queue>
#include<vector>
using namespace std;

void count(bool(&map)[27][27], int n, int(&num), int(&cnt)[600], int i, int j) {
	map[i][j] = 0;
	cnt[num - 1] += 1;

	if (map[i - 1][j]) count(map, n, num, cnt, i - 1, j);
	if (map[i + 1][j]) count(map, n, num, cnt, i + 1, j);
	if (map[i][j - 1]) count(map, n, num, cnt, i, j - 1);
	if (map[i][j + 1]) count(map, n, num, cnt, i, j + 1);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool map[27][27] = { 0 };
	string map2;
	int n, cnt[600] = { 0 }, num = 0;
	cin >> n;
	queue<pair<int, int>> loc;

	for (int i = 1; i <= n; i++) {
		cin >> map2;
		for (int j = 1; j <= n; j++) {
			map[i][j] = map2[j - 1] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (map[i][j]) {
				map[i][j] = 0;
				num++;
				cnt[num - 1]++;

				if (map[i - 1][j]) count(map, n, num, cnt, i - 1, j);
				if (map[i + 1][j]) count(map, n, num, cnt, i + 1, j);
				if (map[i][j - 1]) count(map, n, num, cnt, i, j - 1);
				if (map[i][j + 1]) count(map, n, num, cnt, i, j + 1);
			}

		}
	}


	cout << num << endl;
	sort(cnt, cnt + num);
	for (int i = 0; i < num; i++) {
		cout << cnt[i] << "\n";
	}



}