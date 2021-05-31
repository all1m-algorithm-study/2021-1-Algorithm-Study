#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include<stack>
using namespace std;

int find(int a, int b, bool (&c)[52][52]) {
	c[a][b] = 0;

	for (int i = -1; i <= 1; i++) {
		for (int m = -1; m <= 1; m++) {
			if (c[a + i][b + m]) find(a + i, b + m, c);
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int a, b;
	int num;
	bool map[52][52] = {0};// 패딩까지 만들어 0으로 초기화
	cin >> a >> b;
	while (a != 0 && b != 0) {
		num = 0;
		//먼저 입력을 받는다

		for (int i = 0; i < b; i++) {
			for (int m = 0; m < a; m++) {
				cin >> map[i+1][m+1];
			}
		}
		for (int i = 0; i < b; i++) {
			for (int m = 0; m < a; m++) {
				if (map[i + 1][m + 1]) {
					num++;
					find(i+1,m+1 , map);
				}
			}
		}
		cout << num << "\n";
		//다시 입력을 받는다
		cin >> a >> b;
	}


}