// 1. 왼쪽 회전, 오른쪽 회전을 deque를 통해 수행
// 2. front값이 확인하려는 값과 같으면 중단
// 3. 최소 횟수를 가진 deque를 return
//
// 시간복잡도 = O(n * m) (m번당 2n씩 회전)

#include <iostream>
#include <deque>

using namespace std;

int min_count = 0;

deque<int> circulation(deque<int> &dq, int check) {
	int val;
	int left_min = 0;
	int right_min = 0;
	deque<int> left_circulation = dq;
	deque<int> right_circulation = dq;

	while (left_circulation.front() != check) {
		val = left_circulation.front();
		left_circulation.pop_front();
		left_circulation.push_back(val);
		left_min += 1;
	}
	while (right_circulation.front() != check) {
		val = right_circulation.back();
		right_circulation.pop_back();
		right_circulation.push_front(val);
		right_min += 1;
	}

	left_circulation.pop_front();
	right_circulation.pop_front();

	if (left_min < right_min) {
		min_count += left_min;
		return left_circulation;
	}
	else {
		min_count += right_min;
		return right_circulation;
	}
}
int main(){
	int n, m;
	int check;
	deque<int> dq;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	while (m--) {
		cin >> check;
		dq = circulation(dq, check);
	}
	cout << min_count;

	return 0;
}
