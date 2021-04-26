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
	int a[1000], b[1000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}

	int sum = 0;
	sort(a, a + n);
	int sum2 = 0;

	for (int i = 0; i < n; i++) {
		
		b[i] = a[i] + sum;
		sum += a[i];
		//cout << a[i] << "      " << b[n -1- i] << endl;
		sum2 += b[i];
	}
	cout << sum2;




}