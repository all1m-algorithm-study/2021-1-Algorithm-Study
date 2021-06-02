#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b, num, cnt = 0, zik = 0, a1;
	bool cho[101] = { 0 };
	bool can = 0;
	int c,d;
	int par[101] = { 0 };
	cin >> num >> a >> b >> n;
	for (int i = 0; i < n; i++) {
		cin >> c >> d;
		par[d] = c;
	}
	a1 = a;
	while (1) {
		
		if (par[a]) {
			cho[par[a]] = 1;
			a = par[a];
			
		}
		else break;
	}

	if (cho[b]) {
		zik = 2;
		can = 1;
	}
	while (1) {
		if (par[b]) {
			if (par[b] == a1) {
				zik = 2;
				can = 1;
			}
			if (cho[par[b]]) {
				cho[par[b]] = 0;
				b = par[b];
				can = 1;
			}
			else {
				cho[par[b]] = 1;
				b = par[b];
			}
		}
		else break;
	}


	if (can) {
		for (int i = 1; i <= num; i++) {
			if (cho[i]) cnt++;
		}
		cout << cnt-zik+2;
	}
	else cout << "-1";
}