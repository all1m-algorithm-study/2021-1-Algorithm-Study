/*
* 1. 대기열은 큐, 옆 공간은 스택을 이용한다.
* 2. 대기열이랑 옆 공간에 대기 중인 번호가 존재하면 pop 하고 체크할 번호를 1 증가시킨다.
* 3. 대기열에 대기 중인 인원이 없으면 옆 공간에 대기 중인 번호를 체크한다.
*
* 시간복잡도 = O(n)
*/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool snack(queue<int> &waiting, int n) {
	stack<int> space;
	int order = 1;

	while (!waiting.empty()) {
		// 대기열 체크
		if (!waiting.empty() && order == waiting.front()) {
			order += 1;
			waiting.pop();
		}
		// 옆 공간 체크
		else if (!space.empty() && order == space.top()) {
			order += 1;
			space.pop();
		}
		// 앞 사람을 대기열에서 옆 공간으로 이동
		else if (!waiting.empty() && order != waiting.front()) {
			space.push(waiting.front());
			waiting.pop();
		}		
	}

	// 대기열 탐색 종료 후 옆 공간 탐색
	while (!space.empty()) {
		if (order == space.top()) {
			order += 1;
			space.pop();
		}
		else 			
			return false;		
	}
	return true;
}

int main(){
	int n;
	queue<int> waiting;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		waiting.push(num);
	}
	
	cout << (snack(waiting, n) ? "Nice" : "Sad");
}
