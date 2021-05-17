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
	int n, k;
	int cur=0;
	cin >> n>>k;
	int arr[1001];
	for (int i = 1; i <= 1000; i++) {
		arr[i] = i;
	}

	cout << "<";
	for (int i = 1; i <= n; i++) {
		for (int m = 0; m < k;m++) {
			if (cur < n) {
				cur++;

			}
			else {
				cur = 1;

			}

			while (arr[cur]==0) {
			
			if (cur < n) {
				cur++;

			}
			else {
				cur = 1;

			}
			
			}
				
					
					
				
		}
		cout << arr[cur];
		if (i != n) cout << ", ";
		arr[cur] = 0;
	}
	cout << ">";
	

	
}