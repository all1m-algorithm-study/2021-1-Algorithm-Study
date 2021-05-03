#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, sum = 0;;
	int arr[1001] = {0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	sum += arr[0];
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i - 1];
		sum += arr[i];
	}
	cout << sum;
}