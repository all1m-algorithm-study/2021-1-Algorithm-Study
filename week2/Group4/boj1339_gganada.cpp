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
	
	int alpha[26][8] = { 0 };
	int alphascore[26] = { 0 };
	string a;
	int num;
	int score = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a;
		for (int m = 0; m < size(a); m++) {
		
			alpha[a[m] - 65][size(a)-m-1] +=1;
		}
	}
	for (int i = 0; i < 26; i++) {	
		alphascore[i] += 1 * alpha[i][0];
		alphascore[i] += 10 * alpha[i][1];
		alphascore[i] += 100 * alpha[i][2];
		alphascore[i] += 1000 * alpha[i][3];
		alphascore[i] += 10000 * alpha[i][4];
		alphascore[i] += 100000 * alpha[i][5];
		alphascore[i] += 1000000 * alpha[i][6];
		alphascore[i] += 10000000 * alpha[i][7];
		
	}
	sort(alphascore, alphascore + 26);
	for (int i = 0; i < 9; i++) {
		score += alphascore[25-i] * (9 - i);
	}
	cout << score;
}
