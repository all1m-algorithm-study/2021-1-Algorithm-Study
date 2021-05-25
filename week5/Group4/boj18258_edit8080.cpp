// 1. class를 통한 큐 구성
// 2. 명령어 parsing 함수 구성3
// 3. map을 통한 명령어 Hashing
// 4. 입출력 시간초과 문제 해결

#include <iostream>
#include <string>
#include <vector>
#include <map>

#define QUEUE_SIZE 2000001
#define PUSH 1
#define POP 2
#define SIZE 3
#define EMPTY 4
#define FRONT 5
#define BACK 6

using namespace std;

class queue {
private:
	int arr[QUEUE_SIZE] = { 0 };
	int front_idx = 0;
	int back_idx = 0;

public:
	void push(int n) {
		arr[back_idx++] = n;
	}
	int pop() {
		return front_idx == back_idx ? -1 : arr[front_idx++];
	}
	int size() {
		return back_idx - front_idx;
	}
	int empty() {
		return front_idx == back_idx ? 1 : 0;
	}
	int front() {
		return front_idx == back_idx ? -1 : arr[front_idx];
	}
	int back() {
		return front_idx == back_idx ? -1 : arr[back_idx - 1];
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
	queue* q = new queue();
	map<string, int> command_map = { 
		{"push", PUSH},
		{"pop", POP},
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
		case PUSH: q->push(stoi(split_command[1]));
			break;
		case POP: cout << q->pop() << '\n';
			break;
		case SIZE: cout << q->size() << '\n';
			break;
		case EMPTY: cout << q->empty() << '\n';
			break;
		case FRONT: cout << q->front() << '\n';
			break;
		case BACK: cout << q->back() << '\n';
			break;
		default:
			break;
		}
	}
	return 0;
}