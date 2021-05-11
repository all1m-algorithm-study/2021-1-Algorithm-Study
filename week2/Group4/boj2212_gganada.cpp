#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a,b;
	int len = 0;
	int c[10000];
	vector <pair<int, int>>d;
	int e[1000];
	cin >> a >> b;
	
	for (int i = 0; i < a; i++) {
		cin >> c[i];
	}
	if (a != 1) {
		sort(c, c + a);  // 입력 후 내림차순 정렬
		if (b != 1) {
			for (int i = 0; i < a - 1; i++) {
				d.push_back(pair<int, int>(c[i + 1] - c[i], i));
			}
			sort(d.begin(), d.end()); // 센서 좌표간의 간격 입력 후 내림차순 정렬

			for (int i = 0; i < b - 1; i++) {
				e[i] = d[a - 2 - i].second;
			}
			sort(e, e + b - 1); // 센서 좌표간의 차가 가장 클 때의 왼쪽 index 입력 후 내림차순 정렬


			len += c[e[0]] - c[0];   // 1번째 기지국 수신가능영역 합

			for (int i = 1; i < b - 1; i++) {
				len += c[e[i]] - c[e[i - 1] + 1];
			}										//2번째 ~ b-1번째 기지국 수신가능영역 합
			len += c[a - 1] - c[e[b - 2] + 1];		//b번째 기지국 수신가능영역 합
		}
		else if (b == 1) len = c[a - 1] - c[0];
	}
	else len = 0;
	
	cout << len;							//출력
}
