/*
* 1. 현재 위치에서 n-1, n+1, 2*n 위치로 BFS 탐색구조에 기반해 이동한다.
* 2. 방문한 지점은 체크하여 다시 체크하는 일이 없도록 한다.
* 3. k 위치에 도달할 경우 기존의 최소 시간과 비교한다.
*
* 시간복잡도 = O(3^n) (n : 노드 수)
*/

#include <iostream>
#include <vector>
#include <queue>

#define SIZE 100001

using namespace std;

int n, k;
int search_time = SIZE;
bool visited[SIZE] = { false };

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));

	while (!q.empty()) {
		int start = q.front().first;
		int time = q.front().second;
		q.pop();

		if (start == k) search_time = min(search_time, time);

		if (visited[start]) continue;

		visited[start] = true;

		if (start - 1 >= 0) q.push(make_pair(start - 1, time + 1));
		if (start + 1 <= k) q.push(make_pair(start + 1, time + 1));
		if (start <= k && start * 2 <= SIZE) q.push(make_pair(start * 2, time + 1));
	}
}

int main() {
	cin >> n >> k;

	bfs();
	cout << search_time;
}
