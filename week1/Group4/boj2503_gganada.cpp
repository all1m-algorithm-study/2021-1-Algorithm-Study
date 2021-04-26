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

	int a, c;
	cin >> a;
	int b[5][100];
	for (int i = 0; i < a; i++) {
		cin >> c >> b[3][i] >> b[4][i];
		b[2][i] = c % 10;
		c /= 10;
		b[1][i] = c % 10;
		c /= 10;
		b[0][i] = c;
		b[3][i] = 10 * b[3][i] + b[4][i];

	}
	int d[3][900] = { 0 };
	for (int i = 0; i < 900; i++) {
		int h[3];
		h[0] = (i + 100) % 10;
		h[1] = ((i + 100) / 10) % 10;
		h[2] = (i + 100) / 100;
		if (h[0] != h[1] && h[1] != h[2] && h[0] != h[2] && h[0] && h[1] && h[2]) {
			d[0][i] = h[0];
			d[1][i] = h[1];
			d[2][i] = h[2];
		}
	}
	int score = 0;
	int num = 0;
	int howmany = 0;
	for (int l = 0; l < 900; l++) {
	for (int i = 0; i < a; i++) {
		if (d[0][l] == 0) break;
			for (int m = 0; m < 3; m++) {
				
				for (int k = 0; k < 3; k++) {
					if (b[m][i] == d[k][l]) {
						if (m == k) score += 10;
						else score += 1;
					}
				}
			}
		//	cout << b[3][i] << "-------" << score<<"-----"<<num <<"-------"<<d[0][l]<<d[1][l]<<d[2][l]<< endl;
			if (score == b[3][i]) num++;

			score = 0;

		}
	if (num == a) howmany++;
	num = 0;
//	cout << howmany << endl;
	}



	cout << howmany;



}