#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> list;
vector<int> diff;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> K;

    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        list.push_back(temp);
    }
}

void solve() {
    sort(list.begin(), list.end());

    for(int i=0; i<N-1; i++){
        diff[i] = list[i+1] - list[i];
    }

    sort(diff.begin(), diff.end());

    int sum = 0;
    for(int i=0; i<N-K; i++){
        sum += diff[i];
    }

    cout << sum;
}

int main() {
    init();
    input();
    solve();
}