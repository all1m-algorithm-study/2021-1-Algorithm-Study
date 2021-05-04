#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {

    int N = 0;
    int T;
    cin >> T;
    vector<pair<int, int>> v(T);

    for (int i = 0; i < T; i++) {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    int now = 0;

    //now값보다 v[i].first가 크고 v[i].second가 가장 작은 회의 선택
    //now를 v[i].second로 바꿈

    for (int i = 0; i < T; i++) {
        if (now <= v[i].second) {
            N++;
            now = v[i].first;
        }
        //cout << now<<'\n';
    }
    cout << N;



}

int main() {
    init();
    solve();

}