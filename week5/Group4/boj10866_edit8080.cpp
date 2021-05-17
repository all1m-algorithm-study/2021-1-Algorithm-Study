// 1. class를 통한 덱 구성
//		front (push : 현 위치,  pop/return : 이전 위치)
//		back (push : 다음 위치, pop/return : 현 위치)
// 2. 명령어 parsing 함수 구성
// 3. map을 통한 명령어 Hashing


#include <iostream>
#include <string>
#include <vector>
#include <map>

#define DEQUE_SIZE 20002

enum { PUSH_FRONT, PUSH_BACK, POP_FRONT, POP_BACK, SIZE, EMPTY, FRONT, BACK};

using namespace std;

class deque {
private:
	int arr[DEQUE_SIZE] = { 0 };
	int front_idx = 10000;
	int back_idx = 10000;

public:
	void push_front(int n) {
		arr[front_idx--] = n;			
	}
	void push_back(int n) {
		arr[++back_idx] = n;
	}
	int pop_front() {
		return front_idx == back_idx ? -1 : arr[++front_idx];
	}
	int pop_back() {
		return front_idx == back_idx ? -1 : arr[back_idx--];
	}
	int size() {
		return back_idx - front_idx;
	}
	int empty() {
		return front_idx == back_idx ? 1 : 0;
	}
	int front() {
		return front_idx == back_idx ? -1 : arr[front_idx + 1];
	}
	int back() {
		return front_idx == back_idx ? -1 : arr[back_idx];
	}
};

vector<string> split(string& command, char seperate) {
	int idx = 0;
	vector<string> ret;
	string str = "";

	while (idx < (int)command.length()) {
		if (command[idx] == seperate) {
			ret.push_back(str);
			str = "";
		}
		else {
			str += command[idx];
		}
		idx += 1;
	}
	ret.push_back(str);
	return ret;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	char temp;
	deque* d = new deque();
	map<string, int> command_map = {
		{"push_front", PUSH_FRONT},
		{"push_back", PUSH_BACK},
		{"pop_front", POP_FRONT},
		{"pop_back", POP_BACK},
		{"size",SIZE},
		{"empty",EMPTY},
		{"front",FRONT},
		{"back",BACK} };

	cin >> n;
	temp = cin.get();

	while (n--) {
		string command;
		vector<string> split_command;

		getline(cin, command);
		split_command = split(command, ' ');

		switch (command_map[split_command[0]]) {
		case PUSH_FRONT: d->push_front(stoi(split_command[1]));
			break;
		case PUSH_BACK: d->push_back(stoi(split_command[1]));
			break;
		case POP_FRONT: cout << d->pop_front() << '\n';
			break;
		case POP_BACK: cout << d->pop_back() << '\n';
			break;
		case SIZE: cout << d->size() << '\n';
			break;
		case EMPTY: cout << d->empty() << '\n';
			break;
		case FRONT: cout << d->front() << '\n';
			break;
		case BACK: cout << d->back() << '\n';
			break;
		default:
			break;
		}
	}
	return 0;
}