#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

#include <stdio.h>
#include <math.h>

using namespace std;

int re(int d, int e, int f) {
	if (pow(2, d) < e) {
		if (pow(2, d) < f) {
	
			return 4;
			
		}
		else {
			
			return 2;
		}
	}
	else {
		if (pow(2, d) < f) {
		
			return 3;
		}
		else {
			
			return 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a,b,c;
	cin >> a >> b >> c;
	int num = 0;
	b++;
	c++;
	int sec;
	for (int i = 0; i < a; i++) {
		sec = re(a - 1 - i, c, b);
		num += (sec - 1) * pow(pow(2,a-1-i),2 );
		if (sec == 2 || sec == 4) {
			c = c - pow(2, a -1 - i);
			
		}
		if (sec == 3 || sec == 4) {
			b = b - pow(2, a -1- i);
			

		}
		
		
	}
	cout << num ;

}


