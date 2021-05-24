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

	int a[1000];
	int b, len, arr, cur2,cur, num;
	cin >> b;
	for (int i = 0; i < b; i++) {
		cin >> len >> arr;
		for (int l = 0; l < len; l++) {
			cin >> a[l];
		
		}
		cur = 0;
		cur2 = 0;
		num = 0;

	

		for(int k = 9; k>a[arr]; k--){
			for (int m = 0; m < len; m++) {
				if (cur + m < len) {			// 원래
					if (a[cur + m] == k) {
						num++;
						cur2 = cur + m;
			
					}
				}
				else {							// 벗어났을 때
					if (a[m+cur-len] == k) {
						num++;
						cur2 = m+cur-len;
					}
					
				}
			}
			cur = cur2;
		
		}

		for (int m = 0; m < len; m++) {
			if (cur + m < len) {			// 원래
				if (a[cur + m] == a[arr]) {
					
					num++;
				
					if (cur + m == arr) break;
				}
			}
			else {							// 벗어났을 때
				if (a[m+cur-len] == a[arr] ) {
					num++;
		
					if (m+cur-len == arr) break;
				}

			}
		}
	



		cout << num ;
		if (i != b - 1) cout << "\n";
	}


}