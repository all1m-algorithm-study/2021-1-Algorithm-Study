#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>



using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	int b;
	bool can;
	cin >> b;
	
	for (int i = 0; i < b; i++) {
		can = 1;
		cin >> a;
		for (int m = 0; pow(2, m+1) < size(a) + 1; m++) {
			for (int l = 0; l<(size(a)+1)/pow(2,m+1)-1; l++) {
				if (a[l] == a[(size(a)+1)/pow(2,m) - l-2 ]) {
					can = 0;
					break;
				}
			}
		}
		
		if (can) cout << "YES";
		else cout << "NO";
		if (i != b - 1) cout << "\n";


	}


}