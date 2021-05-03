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

	int a, b, c, d;
	cin >> a;
	b = 0;
	c = 0;
	d = 0;
	int e = 0;
	int f = 0;
	for (int i = 0; i < a; i++) {
		cin >> b;
		while (b>=25) {
			c++;
			b -= 25;
		}
		while (b >=10) {
			d++;
			b -= 10;

		}
		while (b >= 5) {
			e++;
			b -= 5;
		}
		while (b >= 1) {
			f++;
			b -= 1;
		}
		cout << c << " " << d << " " << e << " " << f << "\n";
		c = 0;
		d = 0;
		e = 0;
		f = 0;
	}


}