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
	int b, lst, arr[30001] = { 0 }, d, fst;
	cin >> b;
	lst = 10001;
	fst = 10001;
	for (int i = 0; i < b; i++) {
		cin >> a;
		
		if (!a.compare("push_front")) {
			cin >> d;
			arr[fst-1] = d;
			fst-=1;
		}
		else if (!a.compare("push_back")) {
			cin >> d;
			arr[lst] = d;
			lst++;
		}
		else if (!a.compare("pop_front")) {

			if (lst-fst) {
				cout << arr[fst] << "\n";
				fst++;

			}
			else cout << "-1\n";

		}
		else if (!a.compare("pop_back")) {

			if (lst - fst) {
				cout << arr[lst-1] << "\n";
				lst-=1;

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
				cout << arr[fst] << "\n";

			}
			else cout << "-1\n";
		}
		else if (!a.compare("back")) {
			if (lst - fst) {
				cout << arr[lst-1] << "\n";
			}
			else cout << "-1\n";
		}
		else cout << "error\n";

	}



}