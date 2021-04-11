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

	int a, b;
	int c[1001];
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		cin >> c[i];
	}
	sort(c, c + a);
	int e = 0;
	int current = 0;
	int num = 0;
	while (a>e) {
		while (c[current] - c[e] < b) {
			current++;
		}
		num++;
		e = current;

	}
	cout << num;




}