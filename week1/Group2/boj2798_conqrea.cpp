#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, max = 0;
	int arr[101] = { 0, };
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > max) {
					max = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}
	cout << max;
}