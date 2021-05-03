#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, L;
int list[1001];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> L;

    int temp;
    for (int i = 0; i < N; i++) {
		cin >> list[i];
    }
}

void solve() {
	sort(list, list + N);

	int cnt = 0;
	int next = 0, now = 0;
	while (1)
	{
		if (list[next] - list[now] <= L - 1) {
			next++;

			if (list[next] == 0) {
				cnt++;
				break;
			}
		}
		else//하나의 테이프로 감당안되면 현재 위치 변경
		{
			cnt++;
			now = next;
		}
	}

    cout << cnt;
}

int main() {
    init();
    input();
    solve();
}