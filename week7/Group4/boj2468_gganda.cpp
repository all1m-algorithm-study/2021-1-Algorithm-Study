#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include<stack>
using namespace std;

int find(int a, int b, int(&c)[102][102], int k) {
	c[a][b] = 0;

	if (c[a + 1][b] - k > 0) find(a + 1, b, c, k);
	if (c[a][b + 1] - k > 0) find(a, b + 1, c, k);
	if (c[a - 1][b] - k > 0) find(a - 1, b, c, k);
	if (c[a][b - 1] - k > 0) find(a, b - 1, c, k);


	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int a;
	int num[101] = { 0 };
	int map[102][102] = { 0 };// 패딩까지 만들어 0으로 초기화
	int map2[102][102] = { 0 };
	cin >> a;


	//먼저 입력을 받는다
	for (int i = 0; i < a; i++) {
		for (int m = 0; m < a; m++) {
			cin >> map[i + 1][m + 1];
		}
	}

	for (int k = 0; k <= 100; k++) {
		for (int i = 0; i < a; i++) {		//map2에 map1값 대입
			for (int m = 0; m < a; m++) {
				map2[i + 1][m + 1] = map[i + 1][m + 1];
			}

		}
		for (int i = 0; i < a; i++) {			//섬의 개수 찾기;
			for (int m = 0; m < a; m++) {
				if (map2[i + 1][m + 1] - k > 0) {
					num[k]++;
					find(i + 1, m + 1, map2, k);
				}
			}
		}
	}

	int max = 0;
	for (int i = 0; i <= 100; i++) {
		if (num[i] > max) {
			max = num[i];
		}
	}
	cout << max;


}