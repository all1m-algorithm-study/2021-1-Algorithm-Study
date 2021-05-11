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

	int a;
	int c, d;

	vector<pair<int, int>>b;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> c >> d;
		b.push_back(pair<int, int>(d, c));

	}
	sort(b.begin(), b.end());
	int num = 1;
	int second = 0;
	for (int i = 0; i < a-1; i++) {
		if (b[second].first <= b[i + 1].second) {
			num++;
			second = i + 1;
		}
	}
	cout << num;


}