#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <stack>
using namespace std;

int find(int a, int b, bool(&c)[1002][1002]) {
	c[a][b] = 0;
	if (c[a+1][b]) find(a+1, b, c);
	if (c[a-1][b]) find(a-1, b, c);
	if (c[a ][b+1 ]) find(a , b+1 , c);
	if (c[a][b-1]) find(a, b-1, c);

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int a, b;
	bool can = 0;
	string map1;
	bool map[1002][1002] = { 0 };// 패딩까지 만들어 0으로 초기화
	bool map2[1002] = { 0 };
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		cin >> map1;
		for (int m = 0; m < b; m++) {
			 map[i + 1][m + 1]=!(map1[m]-'0');
			 
		
			 if (i == a - 1) {
				 map2[m + 1] = map[i + 1][m + 1];
			 }
		}
	}


	for (int i = 0; i < b; i++) {
	
		if (map[1][1+i]) {

				find(1, i + 1, map);
		}
		
	}
	
	for (int i = 0; i < b; i++) {
	//	cout << map2[i + 1] << "    " << map[a][i + 1] << endl;
		if (map2[i + 1] != map[a][i + 1]) can = 1;
	}

	if (can) cout << "YES";
	else cout << "NO";
}