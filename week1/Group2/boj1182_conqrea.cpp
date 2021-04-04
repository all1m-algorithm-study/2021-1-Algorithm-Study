#include <iostream>
using namespace std;

int cnt = 0, n , s;
int num[21] = { 0, };
bool v[21];

void SumOfArr(int d, int sum, int lastI) {
	if (sum == s && d > 0) {
		cnt++;
	}
	if (d >= n || lastI == n)
		return;
	for(int i = lastI + 1; i <= n; i++){
		v[i] = true;
		SumOfArr(d + 1, sum + num[i], i);
		v[i] = false;
	}
}

int main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	SumOfArr(0, 0, 0);
	cout << cnt;
}