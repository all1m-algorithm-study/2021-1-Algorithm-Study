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


	int fst = 1, num;
	int arr[1000];

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i-fst+1];
		while (1) {
			if (arr[i - fst + 1] == fst) fst++;
			else break;
		}
	}
	if (num < fst) cout << "Nice";
	else cout << "Sad";


}