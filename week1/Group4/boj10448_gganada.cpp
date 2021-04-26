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

	int a[45] = {1};
	int b;
	int c[1000];

	for (int i = 1; i <= 44; i++) {
		a[i] = (i+2) * (i + 1) / 2;

	}

	cin >> b;
	bool is = 0;
	for (int k = 0; k < b; k++) {
		cin >> c[k];
		is = 0;
		for (int i = 0; i <=44; i++) {
			for (int m = i; m <= 44; m++) {
				for (int l = i; l <= 44; l++) {
					if (a[i] + a[m] + a[l] ==c[k]) {
						c[k] = 1;
						goto bre;
					}
				}
			}
		}
		c[k] = 0;
	bre:;
		
	}
	for (int k = 0; k < b; k++) {
		cout << c[k]<<"\n";
	}

}