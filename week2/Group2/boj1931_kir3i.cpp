#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;  cin >> N;
    v.reserve(N);
    for(int i=0; i<N; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back(pair<int, int>{s, e});
    }

    sort(v.begin(), v.end(), cmp);

    int cnt = 0;
    int last = 0;
    for(int i=0; i<N; i++) {
        if(last<=v[i].first) {
            cnt++;
            last = v[i].second;
        }
    }
    cout << cnt;
}
