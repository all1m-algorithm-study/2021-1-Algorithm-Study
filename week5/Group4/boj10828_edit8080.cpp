// 1. class를 통한 스택 구성
// 2. 명령어 parsing 함수 구성
// 3. map을 통한 명령어 Hashing

#include <iostream>
#include <string>
#include <vector>
#include <map>

#define STACK_SIZE 10001
#define PUSH 1
#define POP 2
#define SIZE 3
#define EMPTY 4
#define TOP 5

using namespace std;

class stack {
	private:
		int arr[STACK_SIZE] = { 0 };
		int current = -1;
	public:
		void push(int n) {
			arr[++current] = n;
		}
		int pop() {
			return current == -1 ? -1 : arr[current--];
		}
		int size() {
			return current + 1;
		}
		int empty() {
			return current == -1 ? 1 : 0;
		}
		int top() {
			return current == -1 ? -1 : arr[current];
		}
};

vector<string> split(string &command, char seperate) {
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

int main(){
	int n;
	stack *s = new stack();
	map<string, int> command_map = { {"push", PUSH}, {"pop", POP}, {"size",SIZE}, {"empty",EMPTY},{"top",TOP} };

	cin >> n;
	getchar();

	while (n--) {
		string command;
		vector<string> split_command;

		getline(cin, command);
		split_command = split(command, ' ');

		switch (command_map[split_command[0]]) {
		case PUSH: s->push(stoi(split_command[1]));
				break;
		case POP: cout << s->pop() << '\n';
				break;
		case SIZE: cout << s->size() << '\n';
				break;
		case EMPTY: cout << s->empty() << '\n';
				break;
		case TOP: cout << s->top() << '\n';
				break;
			default:
				break;
		}
	}
	return 0;
}
