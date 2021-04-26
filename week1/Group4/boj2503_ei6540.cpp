#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>

using namespace std;


void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void solve() {
	bool num[1000];
	memset(num, true, sizeof(num));

	string tmp;
	int test, strike, ball;

	//안쓰는 수 초기화
	for (int i = 123; i <= 987; i++) {
		//i를 손쉽게 string으로 바꾼다
		tmp = to_string(i);
		
		//같은 숫자, 0이 나오면 제외
		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) {
			num[i] = false;
			//cout << "중복으로 제외된 수는: " << i << '\n';
		}
		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') {
			num[i] = false;
		}
	}
	//답이 하나 들어오면 123-987 숫자에 대해 true인지 검사
	int N;
	string one, two;
	cin >> N;
	int s_num, b_num;
	while (N--) {
		cin >> test >> strike >> ball;
		for (int i = 123; i <= 987; i++) {
			s_num = strike;
			b_num = ball;

			if (num[i]) {
				one = to_string(test);
				two = to_string(i);
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {

						//strike는 같은 자리의 숫자가 같다.
						if (j == k && one[j] == two[k]) {
							s_num--;
						}//ball은 다른 자리의 숫자가 같다.
						if (j != k && one[j] == two[k]) {
							b_num--;
						}
					}
				}
				if (b_num != 0 || s_num != 0) {
					num[i] = false;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 123; i <= 987; i++) {
		if (num[i]) {
			ans++;
		}
	}
	cout << ans;
}

int main() {
	init();
	solve();
}
