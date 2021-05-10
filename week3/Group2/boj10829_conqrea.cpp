#include <iostream>
using namespace std;

int main()
{
	unsigned long long int n;
	int arr[100001], i = 0;
	cin >> n;

	while (n != 0) {
		arr[i++] = n % 2;
		n /= 2;
	}
	for (int k = i-1; k >= 0; k--) {
		cout << arr[k];
	}
}