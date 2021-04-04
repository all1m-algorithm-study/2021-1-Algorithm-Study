#include <iostream>
using namespace std;

int qCase[101], qStr[101], qBall[101];

int strikeNum(int n, int t) {
	int cnt = 0;
	if (n / 100 == t / 100)
		cnt++;
	if ((n / 10) % 10 == (t / 10) % 10)
		cnt++;
	if (n % 10 == t % 10)
		cnt++;
	return cnt;
}

int ballNum(int n, int t) {
	int numN[3] = { n / 100, (n / 10) % 10, n % 10 }, numT[3] = { t / 100, (t / 10) % 10, t % 10 }, cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j && numN[i] == numT[j])
			{
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

int main()
{
	int T, cnt = 0;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> qCase[i] >> qStr[i] >> qBall[i];
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i == j || j == k || k == i)
					continue;
				int curNum = i * 100 + j * 10 + k;
				bool checkOk = true;
				for (int l = 1; l <= T; l++) {
					if (strikeNum(curNum, qCase[l]) != qStr[l] || ballNum(curNum, qCase[l]) != qBall[l]) {
						checkOk = false;
						break;
					}
				}
				if (checkOk)
					cnt++;
			}
		}
	}
	cout << cnt;
}