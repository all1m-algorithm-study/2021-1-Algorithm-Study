#include <iostream> 
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include<queue>
#include<vector>
using namespace std;

void bfs(queue<int>(&q), int(&k), int(&num), bool(&check)[100001], int(&a)) {



	a = q.size();

	for (int i = 0; i < a; i++) {

		if (q.front() < 100000) {
			if (!check[q.front() + 1]) {
				q.push(q.front() + 1);
				check[q.front() + 1] = 1;

			}


			if (q.front() <= 50000) {

				if (!check[q.front() * 2]) {
					q.push(q.front() * 2);
					check[q.front() * 2] = 1;

				}
			}
		}
		if (q.front() > 0) {

			if (!check[q.front() - 1]) {
				q.push(q.front() - 1);
				check[q.front() - 1] = 1;

			}
		}

		q.pop();



	}


	if (check[k] == 0) {
		num++;

		bfs(q, k, num, check, a);
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, num = 0, a;
	cin >> n >> k;
	bool check[100001] = { 0 };

	queue<int> q;

	if (n == k) {
		num = 0;
	}
	else if (n > k) {
		num = n - k;
	}
	else {
		q.push(n);
		check[n] = 1;

		bfs(q, k, num, check, a);
		num++;
	}

	cout << num;

}