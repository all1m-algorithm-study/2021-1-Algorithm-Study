#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int T, N;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    cin >> T;

    while (T--) {
        cin >> N;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> list;

        int a, b;
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            list.push({ a, b });
        }

        int min = 1000001;
        int cnt = 0;
        while(!list.empty()){
            int num = list.top().second;
            list.pop();

            if (min > num) {
                cnt++;
                min = num;
            }
        }

        cout << cnt << '\n';
    }
}

int main() {
    init();
    solve();
}