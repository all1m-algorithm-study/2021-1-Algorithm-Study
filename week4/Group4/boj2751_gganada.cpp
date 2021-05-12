#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <stdio.h>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int a[1000000];
	int b;
	cin >> b;
	for (int i = 0; i < b; i++) {
		cin >> a[i];
	}
	sort(a, a + b);
	for (int i = 0; i < b; i++) {
		cout << a[i] << "\n";
	}


}