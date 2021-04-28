#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <stdio.h>


using namespace std;

int re(int a[], int b, int c, int d, bool p, int t) {		//b = 현재 몇번인지, c = 총 몇개인지, d = 끝숫자, p= 출력하는지, t= 올라가는 녀석의 번호
	if (p) {
		for (int i = 0; i < c; i++) {
			cout << a[i + 1];
			if (i + 1 != c) cout << " ";
		}
		if (a[1] == d - c + 1) {
			return 0;
		}
		cout << "\n";
	}
	if (a[1] == d - c + 1) {
		return 0;
	}
	else {
		
		if (b < c) {
			if (b == t) {
				if (a[b] + 1 < a[b + 1]) {

				
					a[b] += 1;
				
					int l = 1;
					for (int m = b+1; m <= c; m++) {
						a[m] = a[b] + l;
						l++;
					}
				
					
					re(a, t, c, d, 1, c);
				}
				else {
			
				
					re(a, 1, c, d, 0, t-1);
			
				}
			}
			re(a, b+1, c, d, 0, t);
		}
		else {
			if (a[b] == d) {
				if (a[b - 1] + 1 == d) {
					re(a, t-1, c, d, 0, t-1);
				}
				else {
					a[b] = a[b - 1] + 2;
					
					re(a, 1, c, d, 0, t-1 );
				}
			}
			else {
				a[b] += 1;
				
				re(a, 1, c, d, 1, t);
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	int a;
	int b;
	int c[9];
	cin >> a >> b;

	
	for (int i = 1; i <= b; i++) {
		c[i] = i;
		
	}
	
	re(c, 1, b, a, 1,b);

}