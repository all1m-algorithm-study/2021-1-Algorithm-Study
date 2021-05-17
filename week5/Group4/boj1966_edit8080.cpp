// 1. 클래스를 통해 큐 구현 (push, pop, empty, front)
// 2. 우선순위값이 체크하려는 목록보다 큰 값이 있으면(is_max) pop 이후 push
// 3. 없으면 order에 현재 순서 저장, 이후 pop
// 
// 시간복잡도 = O(n^2) (역순으로 정렬되어있어서 전부를 탐색할 때)

#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 10000
using namespace std;

class queue {
private:
	pair<int, int> arr[SIZE];
	int front_idx = 0;
	int back_idx = 0;

public:
	void push(pair<int, int> insert) {
		arr[back_idx++] = insert;
	}
	void pop() {
		++front_idx;
	}
	bool empty() {
		return back_idx - front_idx == 0 ? true : false;
	}
	pair<int, int> front() {
		return arr[front_idx];
	}
	bool is_max(int priority) {
		for (int i = front_idx; i < back_idx; i++) {
			if (priority < arr[i].second) return false;
		}
		return true;
	}
};
int main(){
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		int priority;
		int cnt = 1;
		queue q;
		vector<int> order;

		cin >> n >> m;
		order.resize(n);

		for (int i = 0; i < n; i++) {
			cin >> priority;
			q.push(make_pair(i, priority));
		}
		
		while (!q.empty()) {
			pair<int, int> front = q.front();
			if (q.is_max(front.second))
				order[front.first] = cnt++;			
			else 
				q.push(front);			
			q.pop();
		}
		cout << order[m] << '\n';		
	}
	return 0;
}
