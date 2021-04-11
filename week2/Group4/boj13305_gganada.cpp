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
	unsigned int a[100000] = { 0 };
	unsigned int b[100000];
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int i = 0;
	int k = 0;
	unsigned long long sum = 0;
	while (k < n) {
		if (b[k] > b[i]||i==n) {
			for (int m = k; m < i; m++) {
				sum += (unsigned long long)a[m] * (unsigned long long)b[k];
			}
			k = i;
		}
		i++;
		
		
	}
	cout << sum;





}