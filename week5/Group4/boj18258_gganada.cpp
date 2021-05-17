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

	string a, c;
	int b, lst, arr[2000001] = { 0 }, d, fst;
	cin >> b;
	lst = 0;
	fst = 0;
	for (int i = 0; i < b; i++) {
		cin >> a;
		
		if (!a.compare("push")) {
			cin >> d;
			arr[lst + 1] = d;
			lst++;
		}
		else if (!a.compare("pop")) {

			if (lst-fst) {
				cout << arr[fst+1] << "\n";
				fst++;

			}
			else cout << "-1\n";

		}
		else if (!a.compare("size")) {
			cout << lst-fst << "\n";

		}
		else if (!a.compare("empty")) {
			if (lst-fst) {
				cout << "0\n";
			}
			else cout << "1\n";

		}
		else if (!a.compare("front")) {
			if (lst-fst) {
				cout << arr[fst+1] << "\n";

			}
			else cout << "-1\n";
		}
		else if (!a.compare("back")) {
			if (lst - fst) {
				cout << arr[lst] << "\n";
			}
			else cout << "-1\n";
		}
		else cout << "error\n";

	}



}