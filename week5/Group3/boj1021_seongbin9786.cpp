#include <iostream>
#include <deque>

/*
[Silver 4]
회전하는 큐

지민이는 N개의 원소를 포함하고 있는 [양방향 순환 큐]를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.
- 보통 원소가 넘치면 %로 처리해주는 건 양의 방향 하나뿐이기 때문에 굳이 양방향 순환 큐라고 적어놓은 듯하다.

지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. 
(이 위치는 가장 처음 큐에서의 위치이다.) 

이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

[input]
첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다. 
N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다. 
둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 
위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.
*/
using namespace std;

int main()
{
	int i, tmp, target = 0, left, right, total = 0;
	int N, M;
	cin >> N >> M;
	deque<int> targets;
	deque<int> data;
	for (i = 0; i < M; i++)
	{
		cin >> tmp;
		targets.push_back(tmp);
	}
	for (i = 1; i <= N; i++)
		data.push_back(i);

	while (targets.size() > 0)
	{
		/*
		1. 현재 원소 idx=0
		2. 다음 원소 idx를 찾고 [O(n)], min(length - idx, idx);로 왼쪽, 오른쪽 회전을 결정
		3. 실제로 회전을 수행 (회전하면서 횟수++)
		4. 현재 원소 제거 (맨 앞 원소를 제거하는 것이므로 deque 혹은 linked list를 쓰는 게 좋겠다.)
		*/
		for (i = 0; i < data.size(); i++)
			if (targets[0] == data[i]) 
				target = i;

		left = data.size() - target;
		right = target;
		
		if (left > right)
		{
			while (data[0] != targets[0])
			{
				// right 방향으로 이동. 뒤에서 빼서 앞으로 넣자.
				tmp = data.back();
				data.pop_back();
				data.push_front(tmp);
			}
			total += right;
		}
		else
		{
			while (data[0] != targets[0])
			{
				tmp = data.front();
				data.pop_front();
				data.push_back(tmp);
			}
			total += left;
		}
		targets.pop_front();
		data.pop_front();
	}
	cout << total << "\n";
	return 0;
}