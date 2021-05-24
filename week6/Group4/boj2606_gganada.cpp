#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
using namespace std;

	bool numm[101] = { 0 };
	bool arr[101][101] = { 0 };


	int dep(int a) {
		for (int i = 1; i <= 100; i++) {
			if (a != i) {
				if (arr[a][i]&& !numm[i]) {
					numm[i] = 1;
					dep(i);
				}
			}
		}
		return 0;
	}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int num, san;
	int nu = 0;
	cin >> num >> san;
	
	
	int a, b;
	for (int i = 0; i < san; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	
	dep(1);

	for (int i = 1; i <= 100; i++) {
		if (numm[i]) nu++;
	}
	cout << nu-1;

	
}