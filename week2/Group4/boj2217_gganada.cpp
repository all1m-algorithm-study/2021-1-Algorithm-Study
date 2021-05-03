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

	int a,b[100000];
	long c[100000];

	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b[i];
	}
	sort(b, b + a);
	
	for (int i = 0; i < a; i++) {
		c[i] = b[a - 1 - i] * (i + 1);
	}
	int d = c[0];
	for (int i = 0; i < a; i++) {
		if (d < c[i]) {
			d = c[i];
		}
	}
	cout << d;
	

}