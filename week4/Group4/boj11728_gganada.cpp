#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <stdio.h>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int a, b, c[1000000], d[1000000];
	int e = 0, f = 0;
	int sum[2000000] = { 0 };
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < b; i++) {
		cin >> d[i];
	}

	for (int i = 0; i < a + b; i++) {
		if (e < a && f < b) {
			if (c[e] >= d[f]) {
				sum[i] = d[f];
				f++;

			}
			else if (c[e] < d[f]) {
				sum[i] = c[e];
				e++;


			}


		}
		else if (e == a) {
			sum[i] = d[f];
			f++;


		}
		else if (f == b) {
			sum[i] = c[e];
			e++;


		}

		cout << sum[i];
		if (i != a + b - 1) {
			cout << " ";
		}
	}


}
