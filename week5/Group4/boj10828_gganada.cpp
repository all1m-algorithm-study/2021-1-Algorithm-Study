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
	int b, lst, arr[10001] = { 0 }, d;
	cin >> b;
	lst = 0;
	for (int i = 0; i < b; i++) {
		cin >> a;

		if (!a.compare("push")) {
			cin >> d;
			arr[lst + 1] = d;
			lst++;
		}
		else if (!a.compare("pop")) {
			if (lst) {
				cout << arr[lst] << "\n";
				arr[lst] = NULL;
				lst -= 1;

			}
			else cout << "-1\n";

		}
		else if (!a.compare("size")) {
			cout << lst << "\n";

		}
		else if (!a.compare("empty")) {
			if (lst) {
				cout << "0\n";
			}
			else cout << "1\n";

		}
		else if (!a.compare("top")) {
			if (lst) {
				cout << arr[lst] << "\n";

			}
			else cout << "-1\n";
		}
		else cout << "error\n";

	}



}