#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

#include <stdio.h>
#include <math.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a;

	int sz;
	string ss;
	string imsi;
	ss.append(1,'-');
	while ((scanf("%d", &a)) != EOF) {
	

		for (int i = 0; i < a; i++) {
			sz = size(ss);
			imsi = ss;
			ss.append(sz, ' ');
			ss.append(imsi);

		}
		cout <<ss<< "\n";
		ss = '-';
	}
}
