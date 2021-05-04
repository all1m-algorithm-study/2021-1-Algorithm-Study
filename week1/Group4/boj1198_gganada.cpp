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

	int a;
	int b[2][35];
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b[0][i] >> b[1][i];

	}
	unsigned int s =0;
	unsigned int k;
	unsigned int am, bm, cm;
	int sm;
	long double sibal;
	for (int i = 0; i < a-2; i++) {
		for (int m = i + 1; m < a - 1; m++) {
			for (int l = m+1; l < a; l++) {
				am = (b[0][i] * b[1][m]+ b[0][m] * b[1][l]+ b[0][l] * b[1][i] );
				bm = (b[1][i] * b[0][m] +b[1][m] * b[0][l]+ b[1][l] * b[0][i]);
			
				sm = (am-bm);
				if (sm < 0) sm = -sm;
	
				if (s <= sm) s = sm;
			}
		}
	}
	sibal = s / 2;
	printf("%f", s *0.5);

	
}