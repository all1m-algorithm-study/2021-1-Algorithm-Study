#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> list;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool cmp(pair<int, int> p1, pair<int, int>p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

void input() {
    cin >> N;
    list.resize(N);

    int st, en;
    for (int i = 0; i < N; i++) {
        cin >> st >> en;

        list[i] = { st, en };
    }
}

void solve() {
    sort(list.begin(), list.end(), cmp);

    int cnt = 1; // 첫번째는 무조건 선택
    int endTime = list[0].second; // 첫번째의 끝난 시간

    for (int i = 1; i < list.size(); i++) {
        if (list[i].first >= endTime) {
            cnt++;
            endTime = list[i].second;
        }
    }

    cout << cnt;
}

int main() {
    init();
    input();
    solve();
}