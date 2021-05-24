#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//pair의 첫째 값은 진짜 답, 둘째 값은 subset이 0으로 시작하는지 1으로 시작하는지 여부
pair<bool,bool> devide_conquer(string &s, int start, int length) {
	pair<bool, bool> p;

	// base case
	if (length == 3) {
		//길이 3일때 다르면 true와 뭘로 시작하는지 반환
		if (s[start] != s[start + 2]) {
			p = { true, s[start]-'0' };
		}
		//길이 3일때 같으면 false와 false 반환
		else {
			//p.second는 의미없는 false
			p = { false, false };
		}
		return p;
	}


	//양쪽 중간값이 같으면 함수 돌릴 필요 없이 틀림
	if (s[start +length/4]==s[start+length/2+length/4+1]) {
		//p.second는 의미없는 false
		p = { false, false };
	}
	//양쪽 중간값이 다르면 재귀로 작은 경우에 대해 확인해야 함
	else {
		//왼쪽이나 오른쪽 중 하나라도 false가 나오면 false 반환
		pair<bool, bool> left = devide_conquer(s, start, length / 2);
		pair<bool, bool> right = devide_conquer(s, start + 1 + length / 2, length / 2);
		
		//둘 다 true로 판정나면 똑같은걸로 시작하는지 확인한다.
		if (left.first && right.first) {
			if (left.second == right.second) {
				p = { true, left.second };
			}
			else {
				p = { false, false };
			}
		}
		else {
			p = { false, false };
		}
	}
	return p;
}

void solve() {
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		if (s.length() == 1) {
			cout << "YES" << '\n';
		}
		else {
			pair<bool, bool> answer = devide_conquer(s, 0, s.length());
			if (answer.first == true) {
				cout << "YES" << '\n';
			}
			else cout << "NO" << '\n';
		}
	}
}

int main() {
	init();
	solve();
}
