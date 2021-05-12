#include <iostream>
#include <cstring> //문자열의 길이를 재는 strlen을 사용하기 위해 

using namespace std;

// 가운데를 기준으로 양쪽은 반드시 거꾸로 된 모습!
// 0000111

bool check(char paper[], int s, int e) {
	if (s >= e) return true; // 밑의 부분을 검사하고 l이 r보다 크거나 같은 경우에 검사 종료
	int l = s; // 0
	int r = e; // 6

	while (l < r) { // 0<6
		if (paper[l] == paper[r]) return false; //paper[0] ==paper[6], 만약 같으면 아예 false
		l++; // 앞에 부분을 +1
		r--; // 뒤에 부분을 -1 해주어서 마찬가지로 비교
	}
	return check(paper, s, r - 1);
}

int main() {
	char paper[3002]; //문자열의 길이가 3000보다 작아야 하므로
	int t; 
	cin >> t; //test 케이스의 개수만큼 반복해준다
	while (t--) {
		cin >> paper; // 문자열 입력
		int len = strlen(paper); //문자열의 길이
		if (len % 2 == 0) cout << "NO" << endl; //사실 항상 2^N-1꼴이라는 조건이 있어서 없어도 될 것 같기도..
		else if (check(paper, 0, len - 1)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
} 