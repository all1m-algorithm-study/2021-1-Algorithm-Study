#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <string.h>
#include <math.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int a[50], b[50], c,d[50],e;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];

	}
	int sum = 0;
	sort(a, a + n);
	sort(b,b+n );
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[n-i-1];
		//cout << a[i] << "      " << b[n -1- i] << endl;

	}
	cout << sum;




}