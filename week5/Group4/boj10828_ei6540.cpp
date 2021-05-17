#include <iostream>
#include <string>
#include <stack>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
struct Stack {

	int data[10000];//명령의 수
	int size;//스택사이즈, size-1이 top이다.
	Stack() {
		size = 0;
	}
	void push(int num) {
		data[size] = num;
		size += 1;
	}
	bool empty() {
		if (size == 0) {
			return true;
		}
		else return false;
	}
	int pop() {
		if (empty()) {
			return -1;
		}
		else {
			//pop은 출력이므로 줄인 사이즈를 반영해야 한다.
			return data[--size];
		}
	}
	int top() {
		if (empty()) {
			return -1;
		}
		//top은 확인이므로 줄인 사이즈를 반영하면 안된다.
		else return data[size - 1];
	}
};


void solve(){
	
	int n;//명령 개수
	cin >> n;
	Stack s;

	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd == "top") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
		}
		else if (cmd == "size") {
			cout << s.size << '\n';
		}
		else if (cmd == "empty") {
			cout << s.empty() << '\n';
		}
		else if (cmd == "pop") {
			cout << (s.empty() ? -1 : s.pop()) << '\n';
			/*if (!s.empty()) {
				s.pop();
			}*/
		}
	}
}

int main() {
	init();
	solve();
}

