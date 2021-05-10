#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	cin >> a;
	int b;
	bool c = 0;

	for (int i = 0; i < size(a); i++) {
		//cout << i << endl;
		for (int m =0; m < (size(a)-i)/2; m++) {
		
			if (a[m+i] != a[size(a) - m - 1]) break;
			//cout << a[m+i] << "=" << a[size(a) - m - 1] << endl;
			if (m == (size(a) - i) / 2-1) {
				//cout << "youdidit" << endl;
				c = 1;
				
			}

		}
		b = i;
		if (c) {
			
			break;
		}
		
	}
	cout << b + size(a);
	

	
}