/*
* 1. 입력받은 물통 수용량을 기준으로 BFS 탐색을 시작한다.
* 2. 탐색에 A->B, B->C, C->A로 물을 이동시키는 각각의 상황을 설정한다.
* 3. A 물통에 물이 없을 때 C의 상황을 저장한 후 정렬하여 출력한다.
*
* 시간복잡도 = O(n^3) (n : A,B,C 가 될 수 있는 경우의 수)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define SIZE 201

using namespace std;

struct bottle {
	int a;
	int b;
	int c;
};

vector<int> possible;
bool visited[SIZE][SIZE][SIZE] = { 0 };

void bfs(bottle& capacity) {
	queue<bottle> q;
	q.push({ 0, 0, capacity.c });

	while (!q.empty()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		if (!visited[a][b][c]) {
			visited[a][b][c] = true;

			if (a == 0) possible.push_back(c);

			// A -> B
			if (a + b < capacity.b) q.push({ 0, a + b, c });
			else q.push({ a + b - capacity.b, capacity.b, c });

			// B -> A
			if (a + b < capacity.a) q.push({ a + b, 0, c });
			else q.push({ capacity.a, a + b - capacity.a, c });

			// A -> C
			if (a + c < capacity.c) q.push({ 0, b, a + c });
			else q.push({ a + c - capacity.c, b, capacity.c });

			// C -> A
			if (a + c < capacity.a) q.push({ a + c, b, 0 });
			else q.push({ capacity.a , b, a + c - capacity.a });

			// B -> C
			if (b + c < capacity.c) q.push({ a, 0, b + c });
			else q.push({ a, b + c - capacity.c, capacity.c });

			// C -> B
			if (b + c < capacity.b) q.push({ a, b + c, 0 });
			else q.push({ a , capacity.b, b + c - capacity.b });
		}
	}
}

int main() {
	bottle capacity;
	cin >> capacity.a >> capacity.b >> capacity.c;

	bfs(capacity);

	sort(possible.begin(), possible.end());

	for (int i = 0; i < (int)possible.size(); i++)
		cout << possible[i] << ' ';
}
