#include <iostream>
using namespace std;
int main()
{
	int n, sur5, sur3 = -1;
	cin >> n;
	sur5 = n / 5;
	if (sur5 == 0 && n % 3 != 0) {
		cout << -1;
		return 0;
	}
	for (; sur5 >= 0; sur5--) {
		if ((n - sur5 * 5) % 3 == 0) {
			sur3 = (n - sur5 * 5) / 3;
			break;
		}
	}
	if (sur3 == -1)
		cout << -1;
	else
		cout << sur5 + sur3;
}