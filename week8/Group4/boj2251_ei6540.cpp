#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 200 + 1;
int A, B, C;
bool visited[MAX][MAX][MAX];

void solve() {
	
	cin >> A >> B >> C;
	vector<int> v;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, C });

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visited[a][b][c]) {
			continue;
		}
		else {
			visited[a][b][c] = true;
			if (a == 0) v.push_back(c);

			// A to B
			if (a + b > B) q.push({ {a + b - B, B}, c });
			else q.push({ {0, a + b}, c });

			// A to C
			if (a + c > C) q.push({ {a + c - C, b}, C });
			else q.push({ {0, b}, a + c });

			// B to A
			if (b + a > A) q.push({ {A, b + a - A}, c });
			else q.push({ {b + a, 0}, c });

			// B to C
			if (b + c > C) q.push({ {a, b + c - C}, C });
			else q.push({ {a, 0}, b + c });

			// C to A
			if (c + a > A) q.push({ {A, b}, c + a - A });
			else q.push({ {c + a, b}, 0 });

			// C to B
			if (c + b > B) q.push({ {a, B}, c + b - B });
			else q.push({ {a, b + c}, 0 });
		}
	}
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			cout << v[i]<< " ";
		}
}

int main() {
	solve();
}

